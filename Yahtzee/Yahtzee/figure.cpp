#include "figure.h"

std::ostream & coo::operator<<(std::ostream &out, const figure &figure) {
  out << figure.m_nom << ": " << figure.m_points << " point(s)";
  return out;
}
