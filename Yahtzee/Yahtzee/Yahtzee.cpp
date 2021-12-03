// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <iostream>
#include <string>

#include "lancer.h"

int main() {
  coo::lancer lancer;
  for (int i = 0; i < 2; ++i) {
    std::cout << "Lancer numero " + std::to_string(i + 1) << std::endl;
    lancer.tout_lancer();
  }
}
