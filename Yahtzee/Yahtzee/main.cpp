// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <iostream>

#include "graphique.h"
#include "jeu.h"

int main() {

  do {
    coo::graphique::efface();
    coo::jeu *jeu = new coo::jeu;
    jeu->joue();
    delete jeu;

    coo::graphique::pause_et_efface();
    std::cout << "Voulez-vous relancer une partie ? (oui ou non) ";
  }
  while (coo::graphique::demande_oui_non() == 'o');

  coo::graphique::efface();

  std::cout << "Merci d'avoir joue a ce jeu !" << std::endl << std::endl;
  std::cout << "Jeu cree par Abel Amouh et Yannis Sauzeau" << std::endl << std::endl;

  coo::graphique::pause_et_efface();

  return EXIT_SUCCESS;
}
