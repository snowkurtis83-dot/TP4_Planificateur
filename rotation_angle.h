#ifndef ROTATION_ANGLE_H
#define ROTATION_ANGLE_H
#include "actionrobot.h"
#include "contexterobot.h"

class rotation_angle: public ActionRobot
{
private:
    int m_angle=0;
public:
    rotation_angle(int p_angle);
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // ROTATION_ANGLE_H
