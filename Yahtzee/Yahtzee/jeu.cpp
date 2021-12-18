#include "jeu.h"

#include <string>

#include "graphique.h"
#include "figure.h"

namespace coo {

  jeu::jeu()
    : m_nb_manches(figure::nombre_figures), m_lancer(new lancer) {
    std::cout << "Veuillez renseigner le nombre de joueurs (8 max)" << std::endl << std::endl;

    m_nb_joueurs = graphique::demande_choix(1, 8);

    std::string nom;

    for (int i = 1; i <= m_nb_joueurs; ++i) {
        std::cout << std::endl << "Veuillez renseigner le nom du joueur " << i << std::endl;
        std::cin >> nom;

        m_joueurs.push_back(new joueur(nom, m_lancer));
    }

    graphique::efface();
  }

  jeu::jeu(const jeu &jeu) {
      this->m_joueurs = jeu.m_joueurs;
      this->m_lancer = jeu.m_lancer;
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
