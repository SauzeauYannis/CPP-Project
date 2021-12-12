// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <cstdlib>
#include <iomanip>

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

  void graphique::affiche_figures(coo::figure **figures) {
    std::cout << separateur_figures << std::endl;
    std::cout << "|Choix|Combinaisons|Points|Realise|" << std::endl;
    std::cout << separateur_figures << std::endl;
    for (int numero_figure = 1; numero_figure <= figure::nombre_figures; ++numero_figure) {
      std::cout << separateur_figures << std::endl;
      std::cout << std::left << "|  " << std::setw(3) << numero_figure << *figures[numero_figure - 1] << std::endl;
    }
    std::cout << separateur_figures << std::endl;
  }

}
