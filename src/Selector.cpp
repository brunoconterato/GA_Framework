/*
 * Selector.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#include "Selector.h"

Selector::Selector() {
	population = Population::getInstance();
}

Selector::~Selector() {
	// TODO Auto-generated destructor stub
}

void Selector::run() {
	this->sort();
	this->select();
}

void Selector::sort() {
	population.sort();
}
