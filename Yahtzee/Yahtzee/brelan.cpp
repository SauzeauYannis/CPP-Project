// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "brelan.h"
#include "lancer.h"


using namespace coo;

//fais un test sur les valeurs de dés obtenus après lancer et nous retourne la somme
//si c'est le cas et -1 sinon

int coo::brelan::calc_points(const lancer& lancer) {
    int tab[6] = { 0,0,0,0,0,0 };
    bool isBrelan = false;
    int somme = 0;
    for (int i = 0; i < 5; i++) {
        tab[lancer.getDesObtenus().at(i)->valeur()] += 1;
        somme += lancer.getDesObtenus().at(i)->valeur();
        if (tab[lancer.getDesObtenus().at(i)->valeur()] == 3) {
            isBrelan = true;
        }
    }
    if (isBrelan)
        return somme;
    else
        return -1;
}


