// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21

#ifndef PETITE_SUITE_H_
#define PETITE_SUITE_H_

#include "figure.h"
#include "lancer.h"

namespace coo {

	class petiteSuite : public figure {
	public:
		petiteSuite() : figure(partie::partie_inferieur, "Petite suite") {}

		void calc_points(const lancer&) override;

	};

}
#endif