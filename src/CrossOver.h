/*
 * CrossOver.h
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#ifndef CROSSOVER_H_
#define CROSSOVER_H_

class CrossOver {
public:
	CrossOver();
	virtual ~CrossOver();

	void run();

protected:
	virtual void crossElite() = 0;
	virtual void crossAll() = 0;
};

#endif /* CROSSOVER_H_ */
