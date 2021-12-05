// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef LANCER_H_
#define LANCER_H_

#include <vector>
#include<iostream>

namespace coo {

  class de {
    const int m_numero;
    int m_valeur = 0;
  public:
    static constexpr int val_min = 1;
    static constexpr int val_max = 6;

    de(const int numero) : m_numero(numero) {}

    void lance() { m_valeur = val_min + std::rand() % val_max; }

    int valeur() const { return m_valeur; }

    friend std::ostream& operator<<(std::ostream&, const de&);
  };

  std::ostream& operator<<(std::ostream&, const de&);

  class lancer {
    std::vector<de *> m_des;
  public:
    static constexpr int nombre_des = 5;

    lancer();
    lancer(const lancer&);
    ~lancer();

    lancer &operator=(const lancer&);

    void tout_lancer() const;
    void lancer_des(const std::vector<int> &) const;
    std::vector<de*> getDesObtenus() const;
    friend std::ostream &operator<<(std::ostream &, const lancer &);
  };

  std::ostream &operator<<(std::ostream &, const lancer &);

} // namespace coo

#endif // !LANCER_H_
