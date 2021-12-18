#include "jeu.h"

#include <string>

#include "figure.h"

namespace coo {

  jeu::jeu() : m_nb_manches(figure::nombre_figures), m_lancer(new lancer) {

    // TODO Demander le nombre de joueur

    // TODO Pour chaque joueur demander un nom

    // TODO Init les joueurs avec le nom qu'ils ont demandé

    m_joueurs = {
      new joueur("Abel", m_lancer),
      new joueur("Yannis", m_lancer)
    };

  }

  jeu::jeu(const jeu &) {
    // TODO 
  }

  jeu::~jeu() {
    // TODO 
  }

  jeu & jeu::operator=(const jeu &) {
    // TODO
    return *this;
  }

  void jeu::joue_manche() {
    while (m_nb_manches > 0) {
      m_nb_manches--;
      std::cout << "Manche numero " << std::to_string(figure::nombre_figures - m_nb_manches)
                << std::endl << std::endl;

      for (joueur* joueur : m_joueurs) {
        joueur->joue_tour();
      }
    }
  }
}
