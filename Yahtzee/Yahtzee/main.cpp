// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <ctime>
#include <iostream>

#include "jeu.h"

int main() {

  std::srand(std::time(nullptr));

  coo::jeu jeu;

  jeu.joue_manche();

  return 0;
}
