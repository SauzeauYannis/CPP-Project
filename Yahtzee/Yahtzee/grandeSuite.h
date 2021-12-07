// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21
#ifndef GRANDE_SUITE_H_
#define GRANDE_SUITE_H_

#include "figure.h"
#include "lancer.h"

namespace coo {

	class grandeSuite : public figure {
	public:
		grandeSuite() : figure(partie::partie_inferieur, "Grande suite") {}

		void calc_points(const lancer&) override;

	};

}
#endif