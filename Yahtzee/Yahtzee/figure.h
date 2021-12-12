// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef FIGURE_H_
#define FIGURE_H_

#include <iostream>

#include "lancer.h"

namespace coo {

  enum struct partie { partie_superieur, partie_inferieur};

  class figure {
    const partie m_partie;
    const std::string m_nom;
    bool m_est_realisee = false;
  protected:
    unsigned int m_points = 0;
  public:
    static constexpr int nombre_figures = 13;

    figure(const partie &partie, const std::string &nom)
      : m_partie(partie), m_nom(nom) {}

    virtual ~figure() = default;

    virtual void calc_points(const lancer&) = 0;

    void est_choisie() { m_est_realisee = true; }

    friend std::ostream& operator<<(std::ostream&, const figure&);
  };

  std::ostream& operator<<(std::ostream&, const figure&);

} // namespace coo

#endif // !FIGURE_H_
