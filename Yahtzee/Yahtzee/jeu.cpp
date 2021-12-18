#include "jeu.h"

#include <string>

#include "figure.h"

namespace coo {

  jeu::jeu() : m_nb_manches(figure::nombre_figures), m_lancer(new lancer) {

    // TODO Demander le nombre de joueur
      std::cout << "Veuillez renseigner le nombre de joueurs " << std::endl;

      std::cin >> nbJoueurs;

    // TODO Pour chaque joueur demander un nom
          for (int it = 0; it < jeu::nbJoueurs; ++it) {
              std::cout << "Veuillez renseigner le nom du joueur " << it + 1 << std::endl;
              std::cin >> nomJoueur;

              // TODO Init les joueurs avec le nom qu'ils ont demandé
              m_joueurs.push_back(new joueur(nomJoueur, m_lancer));
          }

    

    /*m_joueurs = {
      new joueur("Abel", m_lancer),
      new joueur("Yannis", m_lancer)
    };*/

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
