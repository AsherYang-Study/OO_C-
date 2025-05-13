/*
 * Pig.h
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#ifndef PIG_H_
#define PIG_H_

#include "Pet.h"

class Pig: public Pet {
public:
	Pig();
	Pig(const char* name, string color, int age);
	virtual ~Pig();


	virtual void makeSound();
	virtual void printName();
	virtual void eat();

	virtual void print(std::ostream& os) const;
};

#endif /* PIG_H_ */
