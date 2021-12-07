// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#include "figure_superieure.h"

namespace coo {

  void figure_superieure::calc_points(const lancer& lancer) {
    int sum = 0;
    for (int i = 0; i < lancer::nombre_des; ++i) {
      if (lancer[i].valeur() == m_valeur) {
        sum += m_valeur;
      }
    }
    m_points = sum;
  }

}
