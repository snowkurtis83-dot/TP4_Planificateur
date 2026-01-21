#ifndef FERMERPINCE_H
#define FERMERPINCE_H
#include "actionrobot.h"
#include "contexterobot.h"


class fermerpince: public ActionRobot
{
public:
    fermerpince();
    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // FERMERPINCE_H
