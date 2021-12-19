// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include "jeu.h"

#include <algorithm>
#include <string>

#include "figure.h"
#include "graphique.h"
#include "ia.h"

namespace coo {

  jeu::jeu()
    : m_nb_manches(figure::nombre_figures), m_lancer(std::make_shared<lancer>()) {
    std::cout << "Veuillez renseigner le nombre de joueurs (8 max)" << std::endl << std::endl;

    const int nb_joueurs = graphique::demande_choix(1, 8);

    std::string nom;

    for (int i = 1; i <= nb_joueurs; ++i) {
      std::cout << std::endl << "Veuillez renseigner le nom du joueur " << i << " : ";
      do {
        std::getline(std::cin, nom);
      } while (nom.empty());

      m_joueurs.push_back(std::make_unique<joueur>(nom, m_lancer));
    }

    if (nb_joueurs == 1)
      m_joueurs.push_back(std::make_unique<ia>(m_lancer));

    graphique::efface();
  }

  void jeu::joue() {
    while (m_nb_manches > 0) {
      m_nb_manches--;
      std::cout << "Manche numero " << std::to_string(figure::nombre_figures - m_nb_manches)
        << std::endl << std::endl;

      if (m_nb_manches < figure::nombre_figures - 1) {
        std::cout << "Voulez-vous continuer a jouer ? ";
        if (graphique::demande_oui_non() == 'n') {
          graphique::efface();
          fin();
          return;
        }
        graphique::efface();
      }
      for (const std::unique_ptr<joueur> &joueur : m_joueurs)
        joueur->joue_tour();
    }

    fin();
  }

  void jeu::fin() {
    std::sort(m_joueurs.begin(), m_joueurs.end(),
              [](const std::unique_ptr<joueur> &j1, const std::unique_ptr<joueur>&j2) {
                return j1->points() > j2->points();}
    );

    std::cout << "Fin du jeu !" << std::endl << std::endl;
    std::cout << "Le classement est :" << std::endl;

    for (size_t i = 1; i <= m_joueurs.size(); ++i)
      std::cout << std::to_string(i) << ") " << *m_joueurs[i - 1] << std::endl;

    std::cout << std::endl;
  }

}
