// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <iostream>

#include "graphique.h"
#include "jeu.h"

// Fonction principale du jeu, c'est le point d'entree du programme
int main() {

  // Boucle qui lance un nouveau jeu une première fois
  // et demande de rejouer lorsque le jeu est finie
  // - si l'utilisateur dit oui alors on reste dans la boucle
  // - sinon on sort de la boucle
  do {
    coo::graphique::efface();
    coo::jeu *jeu = new coo::jeu;
    jeu->joue();
    delete jeu;

    coo::graphique::pause_et_efface();
    std::cout << "Voulez-vous relancer une partie ? ";
  } while (coo::graphique::demande_oui_non() == 'o');


  coo::graphique::efface();

  // Fin du jeu, affichage des credits
  std::cout << "Merci d'avoir joue a ce jeu !" << std::endl << std::endl;
  std::cout << "Jeu cree par Abel Amouh et Yannis Sauzeau" << std::endl << std::endl;

  coo::graphique::pause_et_efface();

  return EXIT_SUCCESS;
}
