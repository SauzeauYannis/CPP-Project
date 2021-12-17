#include "joueur.h"

#include "graphique.h"

namespace coo {

  void joueur::joue_tour() {
    std::cout << m_nom << " c'est a votre tour de lancer les des" << std::endl << std::endl;

    graphique::pause();
    graphique::efface();

    for (int i = 1; i <= lancer::nombre_jets; ++i) {
      m_lancer->tout_lancer();

      std::cout << "Le resultat de votre lancer est le suivant:" << std::endl << std::endl;
      std::cout << *m_lancer << std::endl << std::endl;

      for (figure* figure : m_figures) {
        figure->calc_points(*m_lancer);
      }
      graphique::affiche_figures(m_figures);

      std::cout << std::endl << "Il vous reste " << lancer::nombre_jets - i << " jets !" << std::endl << std::endl;

      // TODO Faire un switch avec le choix et faire le traitement pour chaque situation

      std::cout << "Vous avez choisi " << choix_action() << std::endl;

      graphique::pause();
      graphique::efface();
    }
  }

  int joueur::choix_action() {
    int action;
    std::cout << "Que desirez-vous faire ?" << std::endl;
    std::cout << "1) Relancer tous les des" << std::endl;
    std::cout << "2) Selectionner les des a relancer" << std::endl;
    std::cout << "3) Construire une figure a partir de ce lancer" << std::endl << std::endl;
    do {
      std::cout << "Votre choix ? ";
      std::cin >> action;
    } while (action < 1 || action > 3);
    return action;
  }
}
