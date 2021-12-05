// Created by Abel Amouh and Yannis Sauzeau on 05-Dec-21
#ifndef BRELAN_H_
#define BRELAN_H_
#include "figure.h"

namespace coo {

	class brelan : public figure {
	public:
		
		int calc_points(const lancer&) override;
		
	};

}
#endif