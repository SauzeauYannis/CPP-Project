// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21
#ifndef CARRE_H_
#define CARRE_H_
#include "figure.h"

namespace coo {

	class carre : public figure {
	public:

		int calc_points(const lancer&) override;

	};

}
#endif