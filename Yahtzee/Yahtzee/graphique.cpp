// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <cstdlib>

#include "graphique.h"

namespace coo {

  void graphique::pause() {
#if defined _WIN32
    std::system("pause");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    std::cout << "Press <enter> to continue";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
  }

  void graphique::efface() {
#if defined _WIN32
    std::system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    std::system("clear");
#endif
  }

  std::string graphique::affiche_de(const de& de) {
    std::string graphique_de = "-----\n";
    for (int i = 0; i < 3; ++i) {
      graphique_de.push_back('|');
      graphique_de.push_back(rond_de[de.valeur() - 1][i * 3 + 0]);
      graphique_de.push_back(rond_de[de.valeur() - 1][i * 3 + 1]);
      graphique_de.push_back(rond_de[de.valeur() - 1][i * 3 + 2]);
      graphique_de.push_back('|');
      graphique_de.push_back('\n');
    }
    graphique_de.append("-----");
    return graphique_de;
  }

}
