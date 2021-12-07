// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "yahtzee.h"
#include "lancer.h"

namespace coo {

  //fais un test sur les valeurs de d�s obtenus apr�s lancer et nous retourne la somme
  //si c'est le cas et -1 sinon

  void yahtzee::calc_points(const lancer& lancer) {
    int tab[6] = { 0,0,0,0,0,0 };
    bool isYahtzee = false;
    int res = 50;
    for (int i = 0; i < 5; i++) {
      tab[lancer[i].valeur()] += 1;

      if (tab[lancer[i].valeur()] == 5) {
        isYahtzee = true;
      }
    }
    if (isYahtzee)
      m_points = res;
  }

}
