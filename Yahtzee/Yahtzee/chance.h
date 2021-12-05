// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21
#ifndef CHANCE_H_
#define CHANCE_H_
#include "figure.h"

namespace coo {

	class chance : public figure {
	public:

		int calc_points(const lancer&) override;

	};

}
#endif