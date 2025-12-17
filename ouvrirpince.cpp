#include "ouvrirpince.h"
#include <iostream>

void OuvrirPince::afficherNom() const {
    std::cout << "Action : Ouvrir Pince" << std::endl;
}

void OuvrirPince::executer(ContexteRobot& ctx) {
    ctx.ouvrirPince();

}
