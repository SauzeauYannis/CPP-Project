// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef LANCER_H_
#define LANCER_H_

#include <iostream>
#include <vector>

namespace coo {

  class de {
    int m_valeur = 0;
  public:
    static constexpr int val_min = 1;
    static constexpr int val_max = 6;

    void lance() { m_valeur = val_min + std::rand() % val_max; }

    int valeur() const { return m_valeur; }

    friend std::ostream& operator<<(std::ostream&, const de&);
  };

  std::ostream& operator<<(std::ostream&, const de&);

  class lancer {
    unsigned int m_somme_des = 0;
    std::vector<de *> m_des;

    void trier();
  public:
    static constexpr int nombre_des = 5;

    lancer();
    lancer(const lancer&);
    ~lancer();

    lancer &operator=(const lancer&);

    void tout_lancer();
    void lancer_des(const std::vector<int> &);

    unsigned int somme_des() const { return m_somme_des; }

    de& operator[](int de_pos) const { return *m_des[de_pos]; }

    friend std::ostream &operator<<(std::ostream &, const lancer &);
  };

  std::ostream &operator<<(std::ostream &, const lancer &);

} // namespace coo

#endif // !LANCER_H_
