// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#ifndef FIGURE_INFERIEURE_H_
#define FIGURE_INFERIEURE_H_

#include "figure.h"
#include "lancer.h"

namespace coo {

  class figure_inferieure : public figure {
  public:
    figure_inferieure(const std::string& nom) : figure(partie::partie_inferieur, nom) {}
  };

  class chance : public figure_inferieure {
  public:
    chance() : figure_inferieure("Chance") {}

    void calc_points(const lancer& lancer) override { m_points = lancer.somme_des(); }
  };

  template <int longueur_suite>
  class suite : public figure_inferieure {
    const unsigned int m_points_a_gagner;
  public:
    suite(const std::string&nom, int points_a_gagner)
      : figure_inferieure(nom), m_points_a_gagner(points_a_gagner) {}

    void calc_points(const lancer &) override;
  };

  template <int nombre_des_egaux>
  class figure_des_egaux : public figure_inferieure {
    const unsigned int m_points_a_gagner;
  public:
    figure_des_egaux(const std::string& nom, int point_a_gagner = 0)
      : figure_inferieure(nom), m_points_a_gagner(point_a_gagner) {}

    void calc_points(const lancer &) override;
  };

  /*************
   * functions *
   *************/

  template <int longueur_suite>
  void suite<longueur_suite>::calc_points(const lancer &lancer) {
    unsigned int cpt = 1;

    for (int numero_de = 0; numero_de < static_cast<int>(lancer::nombre_des) - 1; numero_de++) {
      if (lancer[numero_de].valeur() + 1 == lancer[numero_de + 1].valeur()) {
        cpt++;
        if (cpt == longueur_suite) {
          m_points = m_points_a_gagner;
          return;
        }
      } else if (lancer[numero_de].valeur() != lancer[numero_de + 1].valeur()) {
        cpt = 1;
      }
    }
    m_points = 0;
  }

  template <int nombre_des_egaux>
  void figure_des_egaux<nombre_des_egaux>::calc_points(const lancer &lancer) {
    unsigned int cpt = 1;

    for (int numero_de = 0; numero_de < static_cast<int>(lancer::nombre_des) - 1; numero_de++) {
      if (lancer[numero_de].valeur() == lancer[numero_de + 1].valeur()) {
        cpt++;
        if (cpt == nombre_des_egaux) {
          m_points = m_points_a_gagner == 0 ? lancer.somme_des() : m_points_a_gagner;
          return;
        }
      } else {
        cpt = 1;
      }
    }
    m_points = 0;
  }

} // namespace coo

#endif // !FIGURE_INFERIEURE_H_
