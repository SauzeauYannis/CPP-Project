// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "grandeSuite.h"
#include "lancer.h"


using namespace coo;


//vérifie dans s'il y'a une suite des 5 dés obtenus et renvoie 
//la valeur de score correspondante si c'est le cas et -1 sinon
int coo::grandeSuite::calc_points(const lancer& lancer) {
    int tab[6] = { 0,0,0,0,0,0 };
    bool smallStraigth = false;
    int res = 40, cpt = 0;
    for (size_t i = 0; i < 5; i++)
        tab[lancer[i].valeur()] += 1;

    for (size_t j = 0; j < 5; j++) {
        if (lancer[j].valeur() == 1 && lancer[j + 1].valeur() == 1) {
            cpt++;
        }
    }
    if (cpt == 5)
        return res;
  return -1;
}


