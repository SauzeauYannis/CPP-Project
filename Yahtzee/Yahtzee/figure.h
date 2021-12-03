// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef FIGURE_H_
#define FIGURE_H_

#include <iostream>

namespace coo {

  enum struct partie { partie_inferieur, partie_superieur };

  class figure {
    const partie m_partie;
    const std::string m_nom;
    unsigned int m_points;
    bool m_est_realisee;
  public:
    figure(const partie&, const std::string&);
  };

} // namespace coo

#endif // !FIGURE_H_
