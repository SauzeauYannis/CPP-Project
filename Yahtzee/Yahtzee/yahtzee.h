// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21
#ifndef YAHTZEE_H_
#define YAHTZEE_H_
#include "figure.h"

namespace coo {

	class yahtzee : public figure {
	public:

		int calc_points(const lancer&) override;

	};

}
#endif