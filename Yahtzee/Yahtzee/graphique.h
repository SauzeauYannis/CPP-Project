// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef GRAPHIQUE_H_
#define GRAPHIQUE_H_

#include <array>
#include <memory>

#include "figure.h"
#include "lancer.h"

namespace coo {
  class de;
  class figure;

  // Classe composee uniquement de methodes statiques
  // qui servent a afficher le jeu dans les meilleurs
  // conditions peut importe l'OS depuis lequel vous
  // lancez le jeu
  class graphique {
    static constexpr char separateur_figures[] = "-----------------------------------";
  public:
    static constexpr char separateur_des[] = "-----";
    static constexpr char rond_de[de::nombre_faces][9] = {
      {' ', ' ', ' ', ' ', 'o', ' ', ' ', ' ', ' '},
      {'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o'},
      {'o', ' ', ' ', ' ', 'o', ' ', ' ', ' ', 'o'},
      {'o', ' ', 'o', ' ', ' ', ' ', 'o', ' ', 'o'},
      {'o', ' ', 'o', ' ', 'o', ' ', 'o', ' ', 'o'},
      {'o', ' ', 'o', 'o', ' ', 'o', 'o', ' ', 'o'},
    };
    static void pause();
    static void efface();
    static void pause_et_efface();
    static void affiche_figures(const std::array<std::unique_ptr<figure>, figure::nombre_figures> &figures);
    static int demande_choix(int, int);
    static char demande_oui_non();
  };

} // namespace coo

#endif // !GRAPHIQUE_H_
