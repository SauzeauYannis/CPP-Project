// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#include "chance.h"
#include "lancer.h"


using namespace coo;

//retourne la valeur du cumul des dés obtenus 

int coo::chance::calc_points(const lancer& lancer) {
    int tab[6] = { 0,0,0,0,0,0 };
    int somme = 0;
    for (int i = 0; i < 5; i++) {
        tab[lancer[i].valeur()] += 1;
        somme += lancer[i].valeur();
        
    }  
  return somme;
}


