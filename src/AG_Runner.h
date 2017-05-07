/*
 * AG.h
 *
 *  Created on: 2 de mai de 2017
 *      Author: brcon
 */

#ifndef AG_RUNNER_H_
#define AG_RUNNER_H_

class AG {
public:
	AG();
	virtual ~AG();

	void run();
	virtual bool stopAchieved()=0;
};

#endif /* AG_RUNNER_H_ */
