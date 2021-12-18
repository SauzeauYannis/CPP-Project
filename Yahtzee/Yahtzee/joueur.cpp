#include "joueur.h"

#include <set>
#include <string>

#include "graphique.h"

namespace coo {

  void joueur::joue_tour() {
    std::cout << m_nom << " c'est a votre tour de lancer les des" << std::endl << std::endl;

    graphique::pause_et_efface();

    m_lancer->tout_lancer();

    for (int i = 1; i < lancer::nombre_jets; ++i) {
      resultat_lancer();

      std::cout << "Il vous reste " << lancer::nombre_jets - i << " jet(s) !" << std::endl << std::endl;
      std::cout << "Que desirez-vous faire ?" << std::endl;
      std::cout << "1) Relancer tous les des" << std::endl;
      std::cout << "2) Selectionner les des a relancer" << std::endl;
      std::cout << "3) Construire une figure a partir de ce lancer" << std::endl << std::endl;

      switch (graphique::demande_choix(1, 3)) {
        case 1:
          m_lancer->tout_lancer();
          break;
        case 2:
          relance_de();
          break;
        case 3:
          choisi_figure();
          graphique::efface();
          return;
        default:
          // TODO Lever une excpetion
          throw 1;
      }

      graphique::efface();
    }

    resultat_lancer();

    std::cout << "C'etait votre dernier lancer, vous devez choisir une figure" << std::endl << std::endl;

    choisi_figure();

    graphique::efface();
  }

  std::ostream &operator<<(std::ostream &out, const joueur &joueur) {
    out << joueur.m_nom << " avec " << std::to_string(joueur.m_points) << " points";
    return out;
  }

  void joueur::choisi_figure() {
    std::cout << "Quelle figure voulez-vous construire ?" << std::endl;
    int choix_figure = 0;
    do {
      choix_figure = graphique::demande_choix(1, figure::nombre_figures);
    }
    while (m_figures[choix_figure - 1]->est_choisie());
    m_figures[choix_figure - 1]->choisir();
    m_points += m_figures[choix_figure - 1]->points();
    if (m_figures[choix_figure - 1]->partie() == partie::partie_superieur) {
      m_points_restant_pour_prime -= static_cast<int>(m_figures[choix_figure - 1]->points());
      if (m_points_restant_pour_prime <= 0) m_points += points_prime;
    }
  }

  void joueur::resultat_lancer() const {
    std::cout << "Le resultat de votre lancer est le suivant:" << std::endl << std::endl;
    std::cout << *m_lancer << std::endl << std::endl;

    for (const std::unique_ptr<figure> &figure : m_figures) {
      if (!figure->est_choisie()) {
        figure->calc_points(*m_lancer);
      }
    }
    graphique::affiche_figures(m_figures);

    std::cout << std::endl
              << (m_points_restant_pour_prime > 0
              ? "Il vous manque " + std::to_string(m_points_restant_pour_prime) + " point(s) pour obtenir "
              : "Vous avez obtenu ")
              << "la prime de " + std::to_string(points_prime) << " points" << std::endl;
    std::cout << "Total de vos points = " << std::to_string(m_points) << std::endl << std::endl;
  }

  void joueur::relance_de() const {
    std::cout << "Combien de des voulez-vous relancer ?" << std::endl;
    const int choix_relance = graphique::demande_choix(1, lancer::nombre_des);
    if (choix_relance == lancer::nombre_des) {
      m_lancer->tout_lancer();
    } else {
      std::set<int> des_a_relancer;
      for (int j = 0; j < choix_relance; ++j) {
        std::cout << "Quel numero de de voulez-vous relancer ?" << std::endl;
        int numero_de = 0;
        do {
          numero_de = graphique::demande_choix(1, lancer::nombre_des);
        } while (des_a_relancer.find(numero_de) != des_a_relancer.end());
        des_a_relancer.insert(numero_de);
      }
      m_lancer->lancer_des(des_a_relancer);
    }
  }

}
