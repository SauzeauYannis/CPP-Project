// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <algorithm>
#include <iostream>

#include "graphique.h"
#include "lancer.h"

namespace coo {

  // Ininitialise le generateur de nombre aleatoire
  // selon une distribution entiere uniforme
  std::mt19937 de::generateur = std::mt19937(std::random_device()());
  std::uniform_int_distribution<> de::alea = std::uniform_int_distribution<>(val_min, val_max);

  lancer::lancer()
    : m_somme_des(0), m_occurence(de::nombre_faces, 0) {
    for (int i = 0; i < nombre_des; ++i)
      m_des.push_back(std::make_unique<de>());
  }

  void lancer::tout_lancer() {
    m_occurence.assign(de::nombre_faces, 0);
    m_somme_des = 0;
    for (const std::unique_ptr<de> &de : m_des) {
      de->lance();
      m_somme_des += de->valeur();
      m_occurence[de->valeur() - 1]++;
    }
  }

  // Fonction qui lance uniquement les des dont les
  // numeros sont dans **des_num**
  void lancer::lancer_des(const std::set<int> &des_num) {
    for (const int num : des_num) {
      m_somme_des -= m_des[num - 1]->valeur();
      m_occurence[m_des[num - 1]->valeur() - 1]--;
      m_des[num - 1]->lance();
      m_somme_des += m_des[num - 1]->valeur();
      m_occurence[m_des[num - 1]->valeur() - 1]++;
    }
  }

  std::ostream &operator<<(std::ostream &out, const lancer &lancer) {
    for (int i = 0; i < lancer::nombre_des; ++i)
      out << graphique::separateur_des << "   ";
    out << std::endl;
    for (int n = 0; n < 3; ++n) {
      for (int i = 0; i < lancer::nombre_des; ++i) {
        out << "|";
        for (int j = 0; j < 3; ++j)
          out << graphique::rond_de[lancer.m_des[i]->valeur() - 1][n * 3 + j];
        out << "|   ";
      }
      out << std::endl;
    }
    for (int i = 0; i < lancer::nombre_des; ++i)
      out << graphique::separateur_des << "   ";
    out << std::endl;
    for (int i = 1; i <= lancer::nombre_des; ++i)
      out << "De " << i << "    ";
    return out;
  }

}
