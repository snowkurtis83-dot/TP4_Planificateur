#ifndef DEPLACER_H
#define DEPLACER_H
#include <vector>
#include "contexterobot.h"
#include "actionrobot.h"

class Deplacer : public ActionRobot{
private:
    double m_dx, m_dy, m_dz;
public:

    Deplacer(double p_dx, double p_dy, double p_dz);
    ~Deplacer() = default;

    void afficherNom() const;
    void executer(ContexteRobot& ctx);
};


#endif // DEPLACER_H
