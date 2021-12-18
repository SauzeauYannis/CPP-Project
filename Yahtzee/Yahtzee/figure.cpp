// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#include "figure.h"

#include <iomanip>

#include "figure_inferieure.h"
#include "figure_superieure.h"

namespace coo {

  std::array<std::unique_ptr<figure>, figure::nombre_figures> figure::init_figures() {
    return {
      std::make_unique<figure_superieure<1>>("As"),
      std::make_unique<figure_superieure<2>>("Deux"),
      std::make_unique<figure_superieure<3>>("Trois"),
      std::make_unique<figure_superieure<4>>("Quatre"),
      std::make_unique<figure_superieure<5>>("Cinq"),
      std::make_unique<figure_superieure<6>>("Six"),
      std::make_unique<figure_des_egaux<3>>("Brelan"),
      std::make_unique<suite<4>>("Petite suite", 30),
      std::make_unique<suite<5>>("Grande suite", 40),
      std::make_unique<figure_des_egaux<3, 2>>("Full", 25),
      std::make_unique<figure_des_egaux<4>>("Carre"),
      std::make_unique<figure_des_egaux<5>>("Yahtzee", 50),
      std::make_unique<figure_des_egaux<0>>("Chance")
    };
  }

  std::ostream& operator<<(std::ostream& out, const figure& figure) {
    out << "|" << std::left << std::setw(12) << figure.m_nom << "|"
        << "  " << std::setw(4) << figure.m_points << "|"
        << "   " << std::setw(4) << (figure.m_est_realisee ? "X" : "") << "|";
    return out;
  }

}
