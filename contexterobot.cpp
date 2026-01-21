#include "contexterobot.h"
#include <iostream>

// Limites autorisées
static const double XMIN = -1000;
static const double XMAX = 1000;
static const double YMIN = -1000;
static const double YMAX = 1000;
static const double ZMIN = 0;
static const double ZMAX = 1000;
static const double RMIN = -360;
static const double RMAX = 360;

// Constructeur
ContexteRobot::ContexteRobot(double p_x, double p_y, double p_z,double p_r, bool p_pince_ouverte)
: m_pince_ouverte(p_pince_ouverte) {
    deplacerVers(p_x, p_y, p_z);
    tournerPince(p_r);
}


// Getters
double ContexteRobot::getX() { return m_x; }
double ContexteRobot::getY() { return m_y; }
double ContexteRobot::getZ() { return m_z; }
double ContexteRobot::getR() { return m_r; }
bool   ContexteRobot::PinceEstOuverte() { return m_pince_ouverte; }

// Actions
void ContexteRobot::deplacerVers(double p_x, double p_y, double p_z) {
    if (p_x < XMIN || p_x > XMAX || p_y < YMIN || p_y > YMAX || p_z < ZMIN || p_z > ZMAX) {
        std::cout << "[ERREUR] Position hors limites, déplacement ignoré." << std::endl;

    }
    else
    {
        m_x = p_x;
        m_y = p_y;
        m_z = p_z;
    }
}

void ContexteRobot::ouvrirPince() {
    if (!m_pince_ouverte) {
        m_pince_ouverte = true;
    }
}

void ContexteRobot::fermerPince() {
    if (m_pince_ouverte) {
        m_pince_ouverte = false;
    }
}
void ContexteRobot::tournerPince(double p_r) {
    if (p_r < XMIN || p_r > XMAX ) {
        std::cout << "[ERREUR] Position hors limites, déplacement ignoré." << std::endl;

    }
    else
    {
        m_r = p_r;
    }
}


// Affichage
void ContexteRobot::afficherPosition() {
    std::cout << "Position : (" << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
    std::cout << "Angle : (" << m_r << ")";
    std::cout << " | Pince " << (m_pince_ouverte ? "ouverte" : "fermée") << std::endl;
}
