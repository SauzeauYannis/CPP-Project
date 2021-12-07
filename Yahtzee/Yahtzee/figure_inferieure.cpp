// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#include "figure_inferieure.h"

namespace coo {

  void full::calc_points(const lancer &lancer) {
    brelan::calc_points(lancer);

    const unsigned int points_brelan = m_points;

    m_points = 0;

    double_paire::calc_points(lancer);

    m_points = points_brelan + m_points > lancer.somme_des() ? 25 : 0;
  }

}
