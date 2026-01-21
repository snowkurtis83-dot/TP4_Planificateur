#include <iostream>
#include <fstream>
#include <string>

#include "contexterobot.h"
#include "sequenceactions.h"
#include "fermerpince.h"
#include "ouvrirpince.h"
#include "deplacer.h"
#include "actionrobot.h"
#include "rotation.h"

int main() {
    ContexteRobot ctx(0, 0, 100, 90, true);

    SequenceActions plan;
    std::ifstream fichier("data/plan.txt");
    if (!fichier.is_open()){
        std::cerr << "Erreur : impossible d'ouvrir le fichier plan.txt" << std::endl;
        return 1;
    }
    std::cerr << "--- Execution du plan ---" << std::endl;
    std::string commande;
    while (fichier >> commande){
        double dx, dy, dz, dr;
        if (commande == "DEPLACER"){
            fichier >> dx >> dy >> dz;
            plan.ajouter(new Deplacer(dx, dy, dz));
        }
        else if (commande == "OUVRIR_PINCE"){
            plan.ajouter(new OuvrirPince());
        }
        else if (commande == "FERMER_PINCE"){
            plan.ajouter(new FermerPince());
        }
        else if (commande == "ROTATION"){
            fichier >> dr;
            plan.ajouter(new Rotation(dr));
        }

        else{
            std::cerr << "commande inconnue : " << commande << std::endl;
        }
    }

    /*plan.ajouter(new OuvrirPince());
    plan.ajouter(new Deplacer(15, 25, 36));
    plan.ajouter(new FermerPince());

    plan.ajouter(new OuvrirPince());
    plan.ajouter(new Deplacer(45, 25, 2));
    plan.ajouter(new FermerPince());
    //plan.ajouter(............................
    */

    plan.executer(ctx);
    std::cerr << std::endl;
    std::cerr << "--- Etat final du robot ---" << std::endl;
    ctx.afficherPosition();

    plan.nettoyer();

    return 0;
}
