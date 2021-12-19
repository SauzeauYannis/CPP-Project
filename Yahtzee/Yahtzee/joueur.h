// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <array>
#include <iostream>
#include <memory>
#include <ostream>

#include "figure.h"
#include "lancer.h"

namespace coo {

  class joueur {
    static constexpr int points_pour_prime = 63;
    static constexpr int points_prime = 35;

    int m_points_restant_pour_prime;
    unsigned int m_points;
  protected:
    const std::string m_nom;
    std::array<std::unique_ptr<figure>, figure::nombre_figures> m_figures;
    std::shared_ptr<lancer> m_lancer;
  public:
    virtual ~joueur() = default;

    joueur(const std::string &nom, const std::shared_ptr<lancer> &lancer)
      : m_points_restant_pour_prime(points_pour_prime), m_points(0),
        m_nom(nom), m_figures(figure::init_figures()), m_lancer(lancer) {}

    unsigned int points() const { return m_points; }

    virtual void joue_tour();

    friend std::ostream &operator<<(std::ostream &, const joueur &);
  protected:
    void change_points(int choix_figure);
    void resultat_lancer() const;
  private:
    void choisi_figure();
    void relance_de() const;
  };

  std::ostream &operator<<(std::ostream &, const joueur &);

} // namespace coo

#endif // !JOUEUR_H_
