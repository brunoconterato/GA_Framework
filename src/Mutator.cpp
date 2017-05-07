/*
 * Mutator.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#include "Mutator.h"

Mutator::Mutator() {
	// TODO Auto-generated constructor stub

}

Mutator::~Mutator() {
	// TODO Auto-generated destructor stub
}

void Mutator::run() {
	this->mutate();
}

double Mutator::getMutationRate() const {
		return mutationRate;
}

void Mutator::setMutationRate(double mutationRate = 0) {
	this->mutationRate = mutationRate;
}
