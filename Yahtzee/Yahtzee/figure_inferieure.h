// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#ifndef FIGURE_INFERIEURE_H_
#define FIGURE_INFERIEURE_H_

#include <iostream>

#include "figure.h"
#include "lancer.h"

namespace coo {

  // Classe abstraitre qui herite de figure et qui represente
  // les figures inferieure du jeu
  class figure_inferieure : public figure {
  protected:
    const unsigned int m_points_a_gagner;
  public:
    explicit figure_inferieure(const std::string &nom, const int points_a_gagner)
      : figure(partie_enum::partie_inferieur, nom), m_points_a_gagner(points_a_gagner) {}
  };

  // Classe patron qui construit une classe qui permet de
  // reconnaitre une figure qui est une suite de des
  // de longueur **longueur_suite**
  template <int longueur_suite>
  class suite final : public figure_inferieure {
  public:
    suite(const std::string &nom, const int points_a_gagner)
      : figure_inferieure(nom, points_a_gagner) {}

    void calc_points(const lancer &) override;
  };

  // Classe patron qui construit une classe qui permet de
  // reconnaitre une figure qui est a deux nombres de des
  // identique, une fois un **nombre_des_egaux** et une
  // autre fois un **nombre_des_egaux_2** qui est initialement
  // egal a 0
  // Pour etre plus clair si vous voulez creer une figure qui
  // a 3 des identiques, vous initialisez **nombre_des_egaux**
  // a 3 et laissez la valeur **nombre_des_egaux_2** par defaut
  // Si vous voulez creer une figure qui a 3 des identiques
  // + 2 des identiques, vous initialisez **nombre_des_egaux**
  // a 3 et **nombre_des_egaux_2** a 2
  template <int nombre_des_egaux, int nombre_des_egaux_2 = 0>
  class figure_des_egaux final : virtual public figure_inferieure {
  public:
    explicit figure_des_egaux(const std::string &nom, const int points_a_gagner = 0)
      : figure_inferieure(nom, points_a_gagner) {}

    void calc_points(const lancer &) override;
  };

  /*************
   * fonctions *
   *************/

  template <int longueur_suite>
  void suite<longueur_suite>::calc_points(const lancer &lancer) {
    // On initialise un compteur qu'on va incrementer
    // a chaque fois que le lancer contient deux des
    // dont leur valeur se suivent
    // - Si ce compteur est egal a **longueur_suite**
    // les points sont egaux au nombre de points a gagner
    // pour la realisation de cette figure
    // - Sinon ils sont egaux a 0
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
    // On donne les points uniquement si les occurences
    // des valeurs des des dans un lancer sont egales
    // ou plus grande que **nombre_des_egaux**
    // et **nombre_des_egaux_2**
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
