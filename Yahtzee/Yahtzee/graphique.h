// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef GRAPHIQUE_H_
#define GRAPHIQUE_H_

#include <iostream>

#include "figure.h"
#include "lancer.h"

namespace coo {
  class de;
  class figure;

  class graphique {
    static constexpr char separateur[] = "-----------------------------------";
    static constexpr char rond_de[de::val_max][9] = {
      {' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' '},
      {'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o'},
      {'o', ' ', ' ', ' ', 'o', ' ', ' ', ' ', 'o'},
      {'o', ' ', 'o', ' ', ' ', ' ', 'o', ' ', 'o'},
      {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
      {'o', ' ', 'o', 'o', ' ', 'o', 'o', ' ', 'o'},
    };
  public:
    static void pause();
    static void efface();
    static void change_curseur_pos(short, short);
    static std::string affiche_de(const de&);
    static void affiche_figures(coo::figure**);
  };

} // namespace coo

#endif // !GRAPHIQUE_H_
