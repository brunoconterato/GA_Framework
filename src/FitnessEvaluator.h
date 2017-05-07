/*
 * FitnessEvaluator.h
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#ifndef FITNESSEVALUATOR_H_
#define FITNESSEVALUATOR_H_

class FitnessEvaluator {
public:
	FitnessEvaluator();
	virtual ~FitnessEvaluator();

	void run();

protected:
	void readResults();
	void wait();
	virtual void evaluate() = 0;

private:
	void printToFile();
};

#endif /* FITNESSEVALUATOR_H_ */
