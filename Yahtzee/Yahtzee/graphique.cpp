// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>

#include "graphique.h"

namespace coo {

  // Fais une pause dand le programme en attendant
  // que le joueur appuit sur la touche entree
  void graphique::pause() {
#if defined _WIN32
    std::system("pause");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    std::cout << "Appuyez sur <entree> pour continuer";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
  }

  // Efface la console
  void graphique::efface() {
#if defined _WIN32
    std::system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
    std::system("clear");
#endif
  }

  void graphique::pause_et_efface() {
    pause();
    efface();
  }

  void graphique::affiche_figures(const std::array<std::unique_ptr<figure>, figure::nombre_figures> &figures) {
    std::cout << separateur_figures << std::endl;
    std::cout << "|Choix|Combinaisons|Points|Realise|" << std::endl;
    std::cout << separateur_figures << std::endl;
    for (int numero_figure = 1; numero_figure <= figure::nombre_figures; ++numero_figure) {
      std::cout << separateur_figures << std::endl;
      std::cout << std::left << "|  " << std::setw(3) << numero_figure << *figures[numero_figure - 1] << std::endl;
    }
    std::cout << separateur_figures << std::endl;
  }

  // Demande a l'utilisateur de rentrer un nombre compris
  // entre **min** et **max**
  int graphique::demande_choix(const int min, const int max) {
    int choix = min - 1;
    do {
      std::cout << "Votre choix ? (entre " << std::to_string(min) << " et " << std::to_string(max) << ") ";
      std::cin >> choix;
      while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cin >> choix;
      }
    } while (choix < min || choix > max);
    return choix;
  }

  // Demande un choix ou il peut repondre par oui ou par non
  char graphique::demande_oui_non() {
    std::cout << " oui (o) ou non (n) ";
    std::string oui_ou_non;
    do {
      std::cin >> oui_ou_non;
    } while (std::tolower(oui_ou_non[0]) != 'o' &&
             std::tolower(oui_ou_non[0]) != 'n');
    return static_cast<char>(std::tolower(oui_ou_non[0]));
  }

}
