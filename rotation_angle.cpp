#include "rotation_angle.h"
#include "contexterobot.h"
#include <iostream>
using namespace std;

rotation_angle::rotation_angle(int p_angle)
{
    m_angle=p_angle;
}

void rotation_angle::executer(ContexteRobot &ctx){
    ctx.rotationAngle(ctx.getAngle()+m_angle);
}

void rotation_angle::afficherNom() const{
    cout <<"Roation de "<<m_angle<<"degres"<<endl;
}
