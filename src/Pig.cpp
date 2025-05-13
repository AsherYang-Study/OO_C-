/*
 * Pig.cpp
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#include "Pig.h"

Pig::Pig() {
	// TODO Auto-generated constructor stub
}
Pig::Pig(const char* name, string color, int age): Pet(name, color, age){
	cout << "Pig constructor called" << endl;
}

Pig::~Pig() {
	// TODO Auto-generated destructor stub
	cout << "Pig destructor called" << endl;
}

void Pig::makeSound(){
	cout<<"Gon Gon!!!"<<endl;
}
void Pig::printName(){
	cout<<"My Pig's name is: "<<getName()<<endl;
}
void Pig::eat(){
	cout<<"eat something fruit!!!"<<endl;
}
void Pig::print(std::ostream& os) const {
    os << "[Cat] Name: " << getName()
       << ", Color: " << getColor()
       << ", Age: " << getAge();
}
