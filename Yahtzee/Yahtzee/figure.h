// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef FIGURE_H_
#define FIGURE_H_

#include <iostream>

#include "lancer.h"

namespace coo {

  enum struct partie { partie_inferieur,partie_superieur };

  class figure {
    const partie m_partie;
    const std::string m_nom;
    unsigned int m_points = 0;
    bool m_est_realisee = false;
  public:
    figure(const partie &partie, const std::string &nom)
      : m_partie(partie), m_nom(nom) {}

    virtual void calc_points(const lancer&) = 0;

    void est_choisie() { m_est_realisee = true; }
  };

  class figure_partie_inf : figure {
    const int m_valeur;
  public:
    figure_partie_inf(const std::string &nom, int valeur)
      : figure(partie::partie_inferieur, nom), m_valeur(valeur) {}

    void calc_points(const lancer &) override;
  };

} // namespace coo

#endif // !FIGURE_H_
