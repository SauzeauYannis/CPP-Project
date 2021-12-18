// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <array>
#include <iostream>
#include <vector>

#include "figure.h"
#include "lancer.h"

namespace coo {

  class joueur {
    const std::string m_nom;
    std::array<figure*, figure::nombre_figures> m_figures;
    lancer* m_lancer;
    std::vector <int> deARelancer;
    int num_de=0;

    static int choix_action();
  public:
    joueur(const std::string &nom, lancer *lancer)
      : m_nom(nom), m_figures(figure::init_figures()), m_lancer(lancer) {}

    void joue_tour();
  };

} // namespace coo

#endif // !JOUEUR_H_
