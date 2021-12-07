// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#ifndef FIGURE_INFERIEURE_H_
#define FIGURE_INFERIEURE_H_

#include "figure.h"
#include "lancer.h"

namespace coo {

  class figure_inferieure : public figure {
  public:
    figure_inferieure() : figure(partie::partie_inferieur, "Full") {} // Default constructor for full
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

  template <int nombre_des_egaux, int nombre_de_fois = 1>
  class figure_des_egaux : virtual public figure_inferieure {
    const unsigned int m_points_a_gagner;
  public:
    figure_des_egaux(const std::string& nom, int point_a_gagner = 0)
      : figure_inferieure(nom), m_points_a_gagner(point_a_gagner) {}

    void calc_points(const lancer &) override;
  };

  class brelan : public figure_des_egaux<3> {
  public:
    brelan() : figure_des_egaux<3>("") {}
  };

  class double_paire : public figure_des_egaux<2, 2> {
  public:
    double_paire() : figure_des_egaux<2, 2>("") {}
  };

  class full : public brelan, public double_paire {
  public:
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

  template <int nombre_des_egaux, int nombre_de_fois>
  void figure_des_egaux<nombre_des_egaux, nombre_de_fois>::calc_points(const lancer &lancer) {
    int nb_fois = nombre_de_fois;
    unsigned int cpt = 1;

    for (int numero_de = 0; numero_de < static_cast<int>(lancer::nombre_des) - 1; numero_de++) {
      if (lancer[numero_de].valeur() == lancer[numero_de + 1].valeur()) {
        cpt++;
        if (cpt == nombre_des_egaux) {
          m_points = m_points_a_gagner == 0 ? lancer.somme_des() : m_points_a_gagner;
          --nb_fois;
          if (nb_fois == 0) return;
          while (numero_de + 1 < lancer::nombre_des && lancer[numero_de].valeur() == lancer[numero_de + 1].valeur()) ++numero_de;
        }
      }
      else {
        cpt = 1;
      }
    }
    m_points = 0;
  }

} // namespace coo

#endif // !FIGURE_INFERIEURE_H_
