/*
 * Dog.h
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#ifndef DOG_H_
#define DOG_H_
#include <string>
#include <iostream>
using namespace std;
#include "Pet.h"

class Dog: public Pet {
public:
	Dog();
	Dog(const char* name, string color, int age);
	virtual ~Dog();

	virtual void makeSound();
	virtual void printName();
	virtual void eat();

	virtual void print(std::ostream& os) const;

};

#endif /* DOG_H_ */
