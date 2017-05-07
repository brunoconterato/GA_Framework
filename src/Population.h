/*
 * Population.h
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include <vector>
using namespace std;

class Population {
public:
	Population(Population const&) = delete; //singleton method
	void operator = (Population const&)  = delete;  //singleton method

	static Population& getInstance();
	virtual ~Population();

	void add(Subject);
	void remove(int);
	void replace(Subject newSubject,int Position);
	void sort();

private:
	Population();
	vector<Subject> population;
};

#endif /* POPULATION_H_ */
