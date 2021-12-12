// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <ctime>
#include <iostream>
#include <string>

#include "figure_inferieure.h"
#include "figure_superieure.h"
#include "graphique.h"
#include "lancer.h"

int main() {

  std::srand(std::time(nullptr));

  coo::figure* figures[] = {
    new coo::figure_superieure<1>("As"),
    new coo::figure_superieure<2>("Deux"),
    new coo::figure_superieure<3>("Trois"),
    new coo::figure_superieure<4>("Quatre"),
    new coo::figure_superieure<5>("Cinq"),
    new coo::figure_superieure<6>("Six"),
    new coo::figure_des_egaux<3>("Brelan"),
    new coo::suite<4>("Petite suite", 30),
    new coo::suite<5>("Grande suite", 40),
    new coo::figure_des_egaux<3, 2>("Full", 25),
    new coo::figure_des_egaux<4>("Carre"),
    new coo::figure_des_egaux<5>("Yahtzee", 50),
    new coo::figure_des_egaux<0>("Chance")
  };

  coo::lancer lancer;
  for (int i = 0; i < 3; ++i) {
    std::cout << "Lancer numero " + std::to_string(i + 1) << std::endl;
    lancer.tout_lancer();
    std::cout << lancer << std::endl;
    for (coo::figure* figure: figures) {
      figure->calc_points(lancer);
      std::cout << *figure << std::endl;
    }
    coo::graphique::pause();
    coo::graphique::efface();
  }

  std::cout << "Lancer numero 4 uniquement sur les des 2 et 4" << std::endl;
  lancer.lancer_des({ 2, 4 });
  std::cout << lancer << std::endl;

  coo::graphique::pause();
  coo::graphique::efface();

  std::cout << "Affichage du premier des du lancer precedent" << std::endl;
  std::cout << lancer[0] << std::endl;

  return 0;
}
