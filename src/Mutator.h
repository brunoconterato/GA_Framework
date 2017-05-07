/*
 * Mutator.h
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#ifndef MUTATOR_H_
#define MUTATOR_H_

class Mutator {
private:
	double mutationRate = 0;

public:
	Mutator();
	virtual ~Mutator();

	void run();

protected:
	virtual void mutate() = 0;
	double getMutationRate() const;
	void setMutationRate(double mutationRate);
};

#endif /* MUTATOR_H_ */
