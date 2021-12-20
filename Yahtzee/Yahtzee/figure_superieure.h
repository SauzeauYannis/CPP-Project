// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#ifndef FIGURE_PARTIE_INF_H_
#define FIGURE_PARTIE_INF_H_

#include <iostream>

#include "figure.h"
#include "lancer.h"

namespace coo {

  // Classe patron qui represente une figure de la
  // partie superieure regarde le nombre de des
  // qui a pour valeur **valeur_des**
  template <int valeur_des>
  class figure_superieure final : public figure {
  public:
    explicit figure_superieure(const std::string &nom)
      : figure(partie_enum::partie_superieur, nom) {}

    void calc_points(const lancer &lancer) override {
      m_points = lancer[valeur_des - 1] * valeur_des;
    }
  };

} // namespace coo

#endif // !FIGURE_PARTIE_INF_H_
