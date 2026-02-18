#ifndef OUVRIRPINCE_H
#define OUVRIRPINCE_H

#include "actionrobot.h"

class OuvrirPince : public ActionRobot {
private:

public:

    ~OuvrirPince() = default;
    void executer(ContexteRobot& ctx);
    void afficherNom() const;
};

#endif // OUVRIRPINCE_H
