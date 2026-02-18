#include "ouvrirpince.h"
#include "contexterobot.h"
#include <iostream>


OuvrirPince::OuvrirPince()
{

}

void OuvrirPince::executer(ContexteRobot& ctx){
    ctx.ouvrirPince() ;
}

void OuvrirPince::afficherNom() const{
    std::cout << "OuvrirPince generique" << std::endl;
}
