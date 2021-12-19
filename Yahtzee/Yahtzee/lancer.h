// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef LANCER_H_
#define LANCER_H_

#include <memory>
#include <ostream>
#include <random>
#include <set>
#include <vector>

namespace coo {

  class de {
  public:
    static constexpr int val_min = 1;
    static constexpr int val_max = 6;
    static constexpr int nombre_faces = val_max - val_min + 1;
  private:
    static std::mt19937 generateur;
    static std::uniform_int_distribution<> alea;
    int m_valeur;
  public:
    de() : m_valeur(val_min) {}

    void lance() { m_valeur = alea(generateur); }

    int valeur() const { return m_valeur; }
  };

  class lancer {
  public:
    static constexpr int nombre_des = 5;
    static constexpr int nombre_jets = 3;
  private:
    unsigned int m_somme_des;
    std::vector<std::unique_ptr<de>> m_des;
    std::vector<int> m_occurence;

  public:
    lancer();

    void tout_lancer();
    void lancer_des(const std::set<int> &);

    unsigned int somme_des() const { return m_somme_des; }

    int operator[](const int de_pos) const { return m_occurence[de_pos]; }

    friend std::ostream &operator<<(std::ostream &, const lancer &);
  };

  std::ostream &operator<<(std::ostream &, const lancer &);

} // namespace coo

#endif // !LANCER_H_
