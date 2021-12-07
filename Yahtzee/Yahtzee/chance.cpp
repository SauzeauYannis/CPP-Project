// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "chance.h"
#include "lancer.h"

namespace coo {

  //retourne la valeur du cumul des dés obtenus 

  void chance::calc_points(const lancer& lancer) {
    int somme = 0;
    for (int i = 0; i < lancer::nombre_des; i++) {
      somme += lancer[i].valeur();
    }
    m_points = somme;
  }

}
