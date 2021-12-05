// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "petiteSuite.h"
#include "lancer.h"


using namespace coo;


//vérifie dans s'il y'a une suite de 4 dés obtenus et renvoie 
//la valeur de score correspondante si c'est le cas et -1 sinon
int coo::petiteSuite::calc_points(const lancer& lancer) {
    int tab[6] = { 0,0,0,0,0,0 };
    int res = 30, cpt = 0;
    for (size_t i = 0; i < 5; i++)
        tab[lancer.getDesObtenus().at(i)->valeur()] += 1;
      
    for (size_t j = 0; j < 5; j++) {
        if (lancer.getDesObtenus().at(j)->valeur() == 1 && lancer.getDesObtenus().at(j+1)->valeur() == 1) {
            cpt++;
        }
    }    
    if (cpt==4)
        return res;
    else
        return -1;
}


