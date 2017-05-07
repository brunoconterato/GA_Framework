/*
 * Population.cpp
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#include "Population.h"
#include <algorithm>

using namespace std;

Population::Population() {
	// TODO Auto-generated constructor stub
}

static Population& Population::getInstance(){
   static Population INSTANCE;
   return INSTANCE;
}

Population::~Population() {
}

void Population::add(Subject subject) {
	population.push_back(subject);
}

void Population::remove(int position) {
	//only c++11
	std::vector<Subject>::iterator iterator = population.begin();
	std::advance(iterator, 10);

	population.erase(iterator);
}

void Population::replace(Subject newSubject, int position) {
	population.at(position) = newSubject;
}

//TODO: resolver problema do sort
void Population::sort() {
	std::sort(population.begin(), population.end(),
			[](Subject *m1, Subject *m2) -> bool { return m1->getFitness() > m2->getFitness(); });
}
