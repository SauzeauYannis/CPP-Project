// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#ifndef FIGURE_PARTIE_INF_H_
#define FIGURE_PARTIE_INF_H_

#include "figure.h"
#include "lancer.h"

namespace coo {

  template <int valeur_des>
  class figure_superieure : public figure {
  public:
    static constexpr int nombre_figure = 6;

    figure_superieure(const std::string& nom)
      : figure(partie::partie_superieur, nom) {}

    void calc_points(const lancer& lancer) override {
      m_points = lancer[valeur_des - 1] * valeur_des;
    }
  };

} // namespace coo

#endif // !FIGURE_PARTIE_INF_H_
