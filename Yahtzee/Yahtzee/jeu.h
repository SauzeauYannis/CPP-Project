// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef JEU_H_
#define JEU_H_

#include <vector>

#include "lancer.h"
#include "joueur.h"

namespace coo {

  class jeu {
    int m_nb_manches;
    int m_nb_joueurs;
    std::vector<joueur*> m_joueurs;
    lancer* m_lancer;
  public:
    jeu();
    jeu(const jeu&);
    ~jeu();

    jeu& operator=(const jeu&);

    void joue_manche();
  };

} // namespace coo

#endif // !JEU_H_
