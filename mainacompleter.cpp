#include <iostream>
#include <fstream>
#include <string>

#include "contexterobot.h"
#include "sequenceactions.h"
#include "fermerpince.h"
#include "ouvrirpince.h"
#include "deplacer.h"
#include "actionrobot.h"
#include "rotation_angle.h"

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
    while (fichier>>commande){
        fichier2<<"Action executee :";
        if (commande =="DEPLACER"){
            double dx, dy, dz;
            fichier >> dx>>dy>>dz;
            plan.ajouter(new deplacer(dx,dy,dz));
            fichier2<<commande<<" | dx="<<dx<<"mm, dy="<<dy<<"mm, dz= "<<dz<<"mm"<<endl;
        }

        else if(commande =="OUVRIR_PINCE"){
            plan.ajouter(new OuvrirPince());
            fichier2<<commande<<endl;
        }
        else if(commande == "FERMER_PINCE"){
            plan.ajouter(new fermerpince());
            fichier2<<commande<<endl;
        }
        else if(commande == "ROTATION"){
            int angle;
            fichier >> angle;
            plan.ajouter(new rotation_angle(angle));
            fichier2<<commande<<" | angle="<< angle<<" degres"<<endl;
        }
        else{
            cerr<<"Commande inconnue :"<<commande<<endl;
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
