#ifndef ROTATION_H
#define ROTATION_H

#include "actionrobot.h"

class Rotation : public ActionRobot {
private:
    double m_dr;
public:

    Rotation(double p_r);
    ~Rotation() = default;
    void executer(ContexteRobot& ctx);
    void afficherNom() const;

};

#endif // ROTATION_H
