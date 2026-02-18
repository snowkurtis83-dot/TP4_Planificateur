#include "contexterobot.h"
#include <iostream>

// Limites autorisées
static const double XMIN = -1000;
static const double XMAX = 1000;
static const double YMIN = -1000;
static const double YMAX = 1000;
static const double ZMIN = 0;
static const double ZMAX = 1000;

// Constructeur
ContexteRobot::ContexteRobot(double p_x, double p_y, double p_z, bool p_pince_ouverte, int angle)
: m_pince_ouverte(p_pince_ouverte) {
    deplacerVers(p_x, p_y, p_z);
    rotationAngle(angle);
}


// Getters
double ContexteRobot::getX() { return m_x; }
double ContexteRobot::getY() { return m_y; }
double ContexteRobot::getZ() { return m_z; }
bool   ContexteRobot::PinceEstOuverte() { return m_pince_ouverte; }
int ContexteRobot::getAngle(){return m_angle;}

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

void ContexteRobot::rotationAngle(int p_angle){
    m_angle=p_angle;
}

// Affichage
void ContexteRobot::afficherPosition() {
    std::cout<<"---Etat final du Robot ---"<<std::endl;
    std::cout << "Position : " << m_x << "mm, " << m_y << "mm, " << m_z << "mm"<<std::endl;
    std::cout << "Pince " << (m_pince_ouverte ? "ouverte" : "fermee")<<std::endl;
    std::cout << "Angle de "<<m_angle<<" degres"<< std::endl;
}

