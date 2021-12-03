// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <algorithm>
#include <string>

#include "lancer.h"

namespace coo {

  de::de(const int numero)
    : m_numero(numero) {
    std::srand(std::time(nullptr));
  }

  lancer::lancer() {
    for (int i = 0; i < nombre_des; ++i) {
      des.push_back(new de(i + 1));
    }
  }

  void lancer::tout_lancer() {
    std::sort(des.begin(), des.end());
    for (de * de : des) {
      de->lance();
      std::cout << "Des numero " + std::to_string(de->numero()) + " a pour valeur " + std::to_string(de->valeur()) << std::endl;
    }
  }

}
