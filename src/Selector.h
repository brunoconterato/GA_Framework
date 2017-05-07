/*
 * Selector.h
 *
 *  Created on: 1 de mai de 2017
 *      Author: brcon
 */

#ifndef SELECTOR_H_
#define SELECTOR_H_

class Selector {
public:
	Selector();
	virtual ~Selector();

	void run();

protected:
	virtual void select() = 0;

private:
	Population population;

	void sort();
};

#endif /* SELECTOR_H_ */
