// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include "ia.h"

#include "figure.h"
#include "graphique.h"

namespace coo {

  void ia::joue_tour() {
    std::cout << m_nom << " lance les des" << std::endl << std::endl;

    graphique::pause_et_efface();

    m_lancer->tout_lancer();

    resultat_lancer();

    unsigned int max_points = 0;
    int figure = 0;

    for (int i = 0; i < figure::nombre_figures; ++i) {
      if (!m_figures[i]->est_choisie()) {
        if (m_figures[i]->points() > max_points) {
          max_points = m_figures[i]->points();
          figure = i;
        }
      }
    }

    change_points(figure + 1);

    std::cout << std::endl << "La figure " << m_figures[figure]->nom()
              << " a ete choisie par " << m_nom << std::endl << std::endl;

    graphique::pause_et_efface();
  }

}
