// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef GRAPHIQUE_H_
#define GRAPHIQUE_H_

#include <iostream>

#include "lancer.h"

namespace coo {

  class de;

  class graphique {
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
    static std::string affiche_de(const de&);
  };

} // namespace coo

#endif // !GRAPHIQUE_H_
