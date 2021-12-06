// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "carre.h"
#include "lancer.h"


using namespace coo;



int coo::carre::calc_points(const lancer& lancer) {
    int tab[6] = { 0,0,0,0,0,0 };
    bool isCarre = false;
    int somme = 0;
    for (int i = 0; i < 5; i++) {
        tab[lancer[i].valeur()] += 1;
        somme += lancer[i].valeur();
        if (tab[lancer[i].valeur()] == 4) {
            isCarre = true;
        }
    }
    if (isCarre)
        return somme;
  return -1;
}


