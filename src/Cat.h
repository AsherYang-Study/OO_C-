/*
 * Cat.h
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#ifndef CAT_H_
#define CAT_H_

#include "Pet.h"
#include <string>
#include <iostream>
using namespace std;
class Cat: public Pet {
public:
	Cat();
	Cat(const char* name, string color, int age);
	virtual ~Cat();


	virtual void makeSound();
	virtual void printName();
	virtual void eat();

	virtual void print(std::ostream& os) const;
};

#endif /* CAT_H_ */
