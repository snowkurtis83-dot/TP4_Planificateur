#include "rotation.h"
#include <iostream>

Rotation::Rotation(double p_r){
    m_dr = p_r;
}
void Rotation::afficherNom() const {
    std::cout << "Action : Tourner de: " << m_dr << std::endl;
}

void Rotation::executer(ContexteRobot& ctx) {
    ctx.tournerPince(ctx.getR()+m_dr);
}
