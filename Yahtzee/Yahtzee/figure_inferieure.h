// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#ifndef FIGURE_INFERIEURE_H_
#define FIGURE_INFERIEURE_H_

#include <iostream>

#include "figure.h"
#include "lancer.h"

namespace coo {

  class figure_inferieure : public figure {
  protected:
    const unsigned int m_points_a_gagner;
  public:
    explicit figure_inferieure(const std::string &nom, const int points_a_gagner)
      : figure(partie::partie_inferieur, nom), m_points_a_gagner(points_a_gagner) {}
  };

  template <int longueur_suite>
  class suite final : public figure_inferieure {
  public:
    suite(const std::string &nom, const int points_a_gagner)
      : figure_inferieure(nom, points_a_gagner) {}

    void calc_points(const lancer &) override;
  };

  template <int nombre_des_egaux, int nombre_des_egaux_2 = 0>
  class figure_des_egaux final : virtual public figure_inferieure {
  public:
    explicit figure_des_egaux(const std::string &nom, const int points_a_gagner = 0)
      : figure_inferieure(nom, points_a_gagner) {}

    void calc_points(const lancer &) override;
  };

  /*************
   * functions *
   *************/

  template <int longueur_suite>
  void suite<longueur_suite>::calc_points(const lancer &lancer) {
    unsigned int cpt = 0;

    for (int face = 0; face < de::nombre_faces; ++face) {
      if (lancer[face] > 0) {
        cpt++;
        if (cpt == longueur_suite) {
          m_points = m_points_a_gagner;
          return;
        }
      } else {
        cpt = 0;
      }
    }
    m_points = 0;
  }

  template <int nombre_des_egaux, int nombre_des_egaux_2>
  void figure_des_egaux<nombre_des_egaux, nombre_des_egaux_2>::calc_points(const lancer &lancer) {
    bool nb_egaux = false;
    bool nb_egaux_2 = false;

    for (int face = 0; face < de::nombre_faces; ++face) {
      if (!nb_egaux && lancer[face] >= nombre_des_egaux) {
        nb_egaux = true;
      } else if (lancer[face] >= nombre_des_egaux_2) {
        nb_egaux_2 = true;
      }
      if (nb_egaux && nb_egaux_2) {
        m_points = m_points_a_gagner == 0 ? lancer.somme_des() : m_points_a_gagner;
        return;
      }
    }
    m_points = 0;
  }

} // namespace coo

#endif // !FIGURE_INFERIEURE_H_
