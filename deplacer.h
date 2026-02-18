#ifndef DEPLACER_H
#define DEPLACER_H
#include "actionrobot.h"


class deplacer: public ActionRobot
{
private:
    double m_dx,m_dy,m_dz;
public:
    deplacer(double p_mx,double p_my, double p_mz);
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // DEPLACER_H
