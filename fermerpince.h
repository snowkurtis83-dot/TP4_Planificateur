#ifndef FERMERPINCE_H
#define FERMERPINCE_H

#include "actionrobot.h"

class FermerPince : public ActionRobot {
private:

public:

    ~FermerPince() = default;
    void executer(ContexteRobot& ctx);
    void afficherNom() const;

};

#endif // FERMERPINCE_H
