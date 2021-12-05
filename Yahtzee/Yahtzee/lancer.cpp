// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <iostream>
#include <algorithm>
#include <string>

#include "graphique.h"
#include "lancer.h"

namespace coo {

  std::ostream& operator<<(std::ostream& out, const de& de) {
    //out << "Des " + std::to_string(de.m_numero) + " = " + std::to_string(de.m_valeur);
    out << std::to_string(de.m_numero) << ")" << std::endl
        << graphique::affiche_de(de) << std::endl;
    return out;
  }

  lancer::lancer() {
    for (int i = 1; i <= nombre_des; ++i) {
      m_des.push_back(new de(i));
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
    /*std::vector<de*> m_des = lancer.m_des;
    std::sort(m_des.begin(), m_des.end(),
              [](const de *d1, const de *d2) {
                return d1->valeur() < d2->valeur();
              });*/
    for (de *de : lancer.m_des) {
      out << *de << std::endl;
    }
    return out;
  }

  std::vector<de*> lancer::getDesObtenus() const {
      return m_des;
  }

}
