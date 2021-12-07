// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include <ctime>
#include <iostream>
#include <string>

#include "figure_superieure.h"
#include "graphique.h"
#include "lancer.h"

#include "chance.h"
#include "petiteSuite.h"
#include "grandeSuite.h"

int main() {

  std::srand(std::time(nullptr));

  coo::figure_superieure figure_superieure[coo::figure_superieure::nombre_figure] = {
    coo::as(), coo::deux(), coo::trois(), coo::quatre(), coo::cinq(), coo::six()
  };

  coo::chance chance;
  coo::petiteSuite petite_suite;
  coo::grandeSuite grande_suite;

  const coo::lancer lancer;
  for (int i = 0; i < 3; ++i) {
    std::cout << "Lancer numero " + std::to_string(i + 1) << std::endl;
    lancer.tout_lancer();
    std::cout << lancer << std::endl;
    for (coo::figure_superieure figure: figure_superieure) {
      figure.calc_points(lancer);
      std::cout << figure << std::endl;
    }
    chance.calc_points(lancer);
    std::cout << chance << std::endl;
    petite_suite.calc_points(lancer);
    std::cout << petite_suite << std::endl;
    grande_suite.calc_points(lancer);
    std::cout << grande_suite << std::endl;
    coo::graphique::pause();
    coo::graphique::efface();
  }

  std::cout << "Lancer numero 4 uniquement sur les des 2 et 4" << std::endl;
  lancer.lancer_des({ 2, 4 });
  std::cout << lancer << std::endl;

  coo::graphique::pause();
  coo::graphique::efface();

  std::cout << "Affichage du premier des du lancer precedent" << std::endl;
  std::cout << lancer[0] << std::endl;

  return 0;
}
