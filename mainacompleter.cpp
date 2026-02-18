#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "contexterobot.h"
#include "sequenceactions.h"
#include "ouvrirpince.h"
#include "fermerpince.h"
#include "deplacer.h"
#include "rotation_angle.h"

using namespace std;

int main() {

    ofstream fichier2("data/journal.txt");
    /*
    if(!fichier2.is_open()){
        cerr<<"Erreur : impossible d'ouvrir le fichier journal.txt"<<endl;
    }
    string cmd;
    while(cmd!="-1"){
        cout<<"Entrez la commande(Faire -1 pour arreter la saisit) :"<<endl;
        getline(cin,cmd);
        if(cmd!="-1"){
            fichier2<<cmd<<endl;
        }

    }
*/
    ifstream fichier("data/plan.txt");
    if(!fichier.is_open()){
        cerr << "Erreur : impossible d'ouvrir le fichier plan.txt"<<endl;
        return 1;
    }
    SequenceActions plan;
    string commande;
    fichier2<<"====Journal D'action====="<<endl<<"Format : Action + Parametres"<<endl<<"=============================="<<endl;
    while (fichier>>commande){
        fichier2<<"Action executee :";
        if (commande =="DEPLACER"){
            double dx, dy, dz;
            if (!(fichier >> dx >> dy >> dz)) {
                std::cerr << "Erreur : parametres invalides pour DEPLACER\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

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
            if (!(fichier >> angle)) {
                std::cerr << "Erreur : parametres invalides pour ROTATION\n";
                fichier.clear();
                fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            plan.ajouter(new rotation_angle(angle));
            fichier2<<commande<<" | angle="<< angle<<" degres"<<endl;
        }
        else{
            cerr<<"Commande inconnue :"<<commande<<endl;
        }

    }
    ContexteRobot ctx(0,0,100,true,0);
    plan.executer(ctx);
    ctx.afficherPosition();
    plan.nettoyer();
/*
//Execution manuel
    ContexteRobot ctx(0, 0, 100, true);
    SequenceActions plan;
    plan.ajouter(new deplacer(100, 0, 0));
    plan.ajouter(new fermerpince());
    plan.ajouter(new OuvrirPince());
    plan.ajouter(new deplacer(100, 10, 0));
    plan.ajouter(new fermerpince());

    plan.executer(ctx);
    ctx.afficherPosition();
    plan.nettoyer();
*/
    return 0;
}
