#include "fermerpince.h"
#include <iostream>

void FermerPince::afficherNom() const {
    std::cout << "Action : Fermer Pince" << std::endl;
}

void FermerPince::executer(ContexteRobot& ctx) {
    ctx.fermerPince();

}
