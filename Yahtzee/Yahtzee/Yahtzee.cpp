// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "yahtzee.h"
#include "lancer.h"


using namespace coo;

//fais un test sur les valeurs de dés obtenus après lancer et nous retourne la somme
//si c'est le cas et -1 sinon

int coo::yahtzee::calc_points(const lancer& lancer) {
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
        return res;
    else
        return -1;
}


