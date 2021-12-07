// Created by Abel Amouh and Yannis Sauzeau on 07-Dec-21

#ifndef FIGURE_PARTIE_INF_H_
#define FIGURE_PARTIE_INF_H_

#include "figure.h"
#include "lancer.h"

namespace coo {

  class figure_superieure : public figure {
    const int m_valeur;
  public:
    static constexpr int nombre_figure = 6;

    figure_superieure(const std::string& nom, int valeur)
      : figure(partie::partie_superieur, nom), m_valeur(valeur) {}

    void calc_points(const lancer&) override;
  };

  class as: public figure_superieure {
  public:
    as() : figure_superieure("As", 1) {}
  };

  class deux: public figure_superieure {
  public:
    deux() : figure_superieure("Deux", 2) {}
  };

  class trois: public figure_superieure {
  public:
    trois() : figure_superieure("Trois", 3) {}
  };

  class quatre: public figure_superieure {
  public:
    quatre() : figure_superieure("Quatre", 4) {}
  };

  class cinq : public figure_superieure {
  public:
    cinq() : figure_superieure("Cinq", 5) {}
  };

  class six: public figure_superieure {
  public:
    six() : figure_superieure("Six", 6) {}
  };

} // namespace coo

#endif // !FIGURE_PARTIE_INF_H_
