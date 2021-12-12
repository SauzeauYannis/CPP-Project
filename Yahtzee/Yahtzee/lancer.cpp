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

  lancer::lancer() : m_occurence(de::nombre_faces, 0) {
    for (int i = 0; i < nombre_des; ++i) {
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

  void lancer::tout_lancer() {
    m_occurence.assign(de::nombre_faces, 0);
    m_somme_des = 0;
    for (de * de : m_des) {
      de->lance();
      m_somme_des += de->valeur();
      m_occurence[de->valeur() - 1]++;
    }
  }

  void lancer::lancer_des(const std::vector<int>& des_num) {
    for (const int num : des_num) {
      m_somme_des -= m_des[num - 1]->valeur();
      m_occurence[m_des[num - 1]->valeur() - 1]--;
      m_des[num - 1]->lance();
      m_somme_des += m_des[num - 1]->valeur();
      m_occurence[m_des[num - 1]->valeur() - 1]++;
    }
  }

  void lancer::trier() {
    std::sort(m_des.begin(), m_des.end(),
      [](const de* d1, const de* d2) {
        return d1->valeur() < d2->valeur();
      });
  }

  std::ostream &operator<<(std::ostream &out, const lancer &lancer) {
    for (int i = 0; i < static_cast<int>(lancer.m_des.size()); ++i) {
      out << i + 1 << ")" << std::endl
          << *lancer.m_des[i] << std::endl;
    }
    return out;
  }

}
