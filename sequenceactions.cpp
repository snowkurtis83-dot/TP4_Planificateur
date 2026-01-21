#include <thread>
#include <chrono>
#include "iostream"
using namespace std;

#include "sequenceactions.h"


void SequenceActions::ajouter(ActionRobot* p_action) {
    m_actions.push_back(p_action);
}

void SequenceActions::executer(ContexteRobot& ctx) {
    cout<<"---Execution du plan ---"<<endl;
    for (std::size_t i = 0; i < m_actions.size(); ++i) {
        cout<<"Action : ";
        m_actions[i]->executer(ctx);
        m_actions[i]->afficherNom();
        cout<<"Action : Attendre 200ms"<<endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

void SequenceActions::nettoyer() {
    for (std::size_t i = 0; i < m_actions.size(); ++i) {
        delete m_actions[i];
    }
    m_actions.clear();
}
