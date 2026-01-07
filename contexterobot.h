#ifndef CONTEXTEROBOT_H
#define CONTEXTEROBOT_H

class ContexteRobot {
private:
    double m_x, m_y, m_z, m_r;
    bool m_pince_ouverte;

public:
    // Constructeur
    ContexteRobot(double p_x, double p_y, double p_z,double p_r, bool p_pince_ouverte);

    // Accès lecture
    double getX();
    double getY();
    double getZ();
    double getR();
    bool PinceEstOuverte();

    // Actions
    void deplacerVers(double p_x, double p_y, double p_z);
    void ouvrirPince();
    void fermerPince();
    void tournerPince(double p_r);

    // Affichage
    void afficherPosition();
};

#endif // CONTEXTEROBOT_H
