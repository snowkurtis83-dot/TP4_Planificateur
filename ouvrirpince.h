#ifndef OUVRIRPINCE_H
#define OUVRIRPINCE_H
#include "actionrobot.h"
#include "contexterobot.h"


class OuvrirPince: public ActionRobot
{
public:
    OuvrirPince();
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // OUVRIRPINCE_H
