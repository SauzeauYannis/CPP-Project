// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <iostream>
#include <algorithm>
#include <string>

#include "graphique.h"
#include "lancer.h"

namespace coo {

  std::ostream& operator<<(std::ostream& out, const de& de) {
    out << graphique::affiche_de(de) << std::endl;
    return out;
  }

  lancer::lancer() {
    for (int i = 1; i <= nombre_des; ++i) {
      m_des.push_back(new de);
    }
  }

  lancer::lancer(const lancer &) {
    // TODO 
  }

  lancer::~lancer() {
    for (de * de : m_des) {
      delete de;
    }
  }

  lancer & lancer::operator=(const lancer &) {
    // TODO
    return *this;
  }

  void lancer::tout_lancer() const {
    for (de * de : m_des) {
      de->lance();
    }
  }

  void lancer::lancer_des(const std::vector<int>& des_num) const {
    for (const int num : des_num) {
      m_des[num - 1]->lance();
    }
  }

  std::ostream &operator<<(std::ostream &out, const lancer &lancer) {
    for (int i = 0; i < static_cast<int>(lancer.m_des.size()); ++i) {
      out << i + 1 << ")" << std::endl
          << *lancer.m_des[i] << std::endl;
    }
    return out;
  }

}
