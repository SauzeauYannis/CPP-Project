// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21
#ifndef FULL_H_
#define FULL_H_
#include "figure.h"

namespace coo {

	class full : public figure {
	public:

		int calc_points(const lancer&) override;

	};

}
#endif