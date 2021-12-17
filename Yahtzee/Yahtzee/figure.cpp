#include <iomanip>

#include "figure.h"

#include "figure_inferieure.h"
#include "figure_superieure.h"

namespace coo {

  std::ostream& operator<<(std::ostream& out, const figure& figure) {
    out << "|" << std::left << std::setw(12) << figure.m_nom << "|"
        << "  " << std::setw(4) << figure.m_points << "|"
        << "   " << std::setw(4) << (figure.m_est_realisee ? "X" : "") << "|";
    return out;
  }

  std::array<figure*, figure::nombre_figures> figure::init_figures() {
    return {
      new figure_superieure<1>("As"),
      new figure_superieure<2>("Deux"),
      new figure_superieure<3>("Trois"),
      new figure_superieure<4>("Quatre"),
      new figure_superieure<5>("Cinq"),
      new figure_superieure<6>("Six"),
      new figure_des_egaux<3>("Brelan"),
      new suite<4>("Petite suite", 30),
      new suite<5>("Grande suite", 40),
      new figure_des_egaux<3, 2>("Full", 25),
      new figure_des_egaux<4>("Carre"),
      new figure_des_egaux<5>("Yahtzee", 50),
      new figure_des_egaux<0>("Chance")
    };
  }

}
