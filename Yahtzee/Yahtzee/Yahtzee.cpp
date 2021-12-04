// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <iostream>
#include <string>

#include "lancer.h"

int main() {

  std::srand(std::time(nullptr));

  coo::lancer lancer;
  for (int i = 0; i < 3; ++i) {
    std::cout << "Lancer numero " + std::to_string(i + 1) << std::endl;
    lancer.tout_lancer();
    std::cout << lancer << std::endl;
  }

  std::cout << "Lancer numero 4 uniquement sur les des 2 et 4" << std::endl;
  lancer.lancer_des({ 2, 4 });
  std::cout << lancer << std::endl;
}
