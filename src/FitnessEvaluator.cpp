/*
 * FitnessEvaluator.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#include "FitnessEvaluator.h"

FitnessEvaluator::FitnessEvaluator() {
	// TODO Auto-generated constructor stub

}

FitnessEvaluator::~FitnessEvaluator() {
	// TODO Auto-generated destructor stub
}

void FitnessEvaluator::run() {
	this->readResults();
	this->evaluate();
	this->wait();
	this->printToFile();
}

void FitnessEvaluator::readResults() {
}

void FitnessEvaluator::wait() {
}

void FitnessEvaluator::printToFile() {
}
