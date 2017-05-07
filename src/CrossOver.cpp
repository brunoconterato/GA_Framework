/*
 * CrossOver.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#include "CrossOver.h"

CrossOver::CrossOver() {
	// TODO Auto-generated constructor stub
}

CrossOver::~CrossOver() {
	// TODO Auto-generated destructor stub
}

void CrossOver::run() {
	crossElite();
	crossAll();
}
