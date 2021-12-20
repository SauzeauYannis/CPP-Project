// Created by Abel Amouh and Yannis Sauzeau on 03-Dec-21

#ifndef IA_H_
#define IA_H_

#include "joueur.h"

namespace coo {

  // Classe qui herite de joueur et qui represente
  // un IA jouee par l'ordinateur
  class ia final : public joueur {
  public:
    explicit ia(const std::shared_ptr<lancer>& lancer)
      : joueur("Ordinateur", lancer) {}

    void joue_tour() override;
  };

} // namespace coo

#endif // !IA_H_
