#include "fermerpince.h"
#include "contexterobot.h"
#include <iostream>

fermerpince::fermerpince()
{
}

void fermerpince::executer(ContexteRobot& ctx){
    ctx.fermerPince() ;
}

void fermerpince::afficherNom() const{
    std::cout << "FermerPince generique" << std::endl;
}
