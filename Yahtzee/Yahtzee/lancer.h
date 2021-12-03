// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef LANCER_H_
#define LANCER_H_

#include <iostream>
#include <vector>

namespace coo {

  constexpr int nombre_des = 6;

  class de {
    const int m_numero;
    int m_valeur = 0;
  public:
    de(int);

    void lance() { m_valeur = 1 + std::rand() % 6; }

    int valeur() const { return m_valeur; }
    int numero() const { return m_numero; }
  };

  class lancer {
    std::vector<de *> des;
  public:
    lancer();
    lancer(const lancer& lancer);
    //~lancer();

    lancer& operator=(const lancer& lancer);

    void tout_lancer();
  };

} // namespace coo

#endif // !LANCER_H_
