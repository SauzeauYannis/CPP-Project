// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21
#ifndef CHANCE_H_
#define CHANCE_H_

#include "figure.h"
#include "lancer.h"

namespace coo {

	class chance : public figure {
	public:
		chance() : figure(partie::partie_inferieur, "Chance") {}

		void calc_points(const lancer&) override;

	};

}
#endif