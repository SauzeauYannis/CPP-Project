#include <iomanip>

#include "figure.h"

namespace coo {

  std::ostream& operator<<(std::ostream& out, const figure& figure) {
    out << "|" << std::left << std::setw(12) << figure.m_nom << "|"
        << "  " << std::setw(4) << figure.m_points << "|"
        << "   " << std::setw(4) << (figure.m_est_realisee ? "X" : "") << "|";
    return out;
  }

}
