// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef JEU_H_
#define JEU_H_

#include <memory>
#include <vector>

#include "lancer.h"
#include "joueur.h"

namespace coo {

  class jeu {
    int m_nb_manches;
    std::vector<std::unique_ptr<joueur>> m_joueurs;
    std::shared_ptr<lancer> m_lancer;
  public:
    jeu();

    void joue();
    void fin();
  };

} // namespace coo

#endif // !JEU_H_
