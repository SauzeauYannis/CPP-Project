// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "petiteSuite.h"
#include "lancer.h"

namespace coo {

  //vérifie dans s'il y'a une suite de 4 dés obtenus et renvoie 
  //la valeur de score correspondante si c'est le cas et -1 sinon

  void petiteSuite::calc_points(const lancer& lancer) {
    int res = 30, cpt = 0;

    for (size_t j = 0; j < lancer::nombre_des - 1; j++) {
      if (lancer[j].valeur() == 1 && lancer[j + 1].valeur() == 1) {
        cpt++;
      }
    }
    if (cpt == 4)
      m_points = res;
    else
      m_points = 0;
  }

}
