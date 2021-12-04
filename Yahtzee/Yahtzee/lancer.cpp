// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <algorithm>
#include <string>

#include "lancer.h"

namespace coo {

  std::ostream& operator<<(std::ostream& out, const de& de) {
    out << "Des " + std::to_string(de.m_numero) + " = " + std::to_string(de.m_valeur);
    return out;
  }

  lancer::lancer() {
    for (int i = 1; i <= nombre_des; ++i) {
      des.push_back(new de(i));
    }
  }

  void lancer::tout_lancer() const {
    for (de * de : des) {
      de->lance();
    }
  }

  void lancer::lancer_des(const std::vector<int>& des_num) const {
    for (const int num : des_num) {
      des[num - 1]->lance();
    }
  }

  std::ostream &operator<<(std::ostream &out, const lancer &lancer) {
    std::vector<de*> des = lancer.des;
    std::sort(des.begin(), des.end(),
              [](const de *d1, const de *d2) {
                return d1->valeur() < d2->valeur();
              });
    for (de *de : des) {
      out << *de << std::endl;
    }
    return out;
  }

}
