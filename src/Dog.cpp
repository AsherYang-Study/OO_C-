/*
 * Dog.cpp
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#include "Dog.h"

Dog::Dog() {
	// TODO Auto-generated constructor stub
}
Dog::Dog(const char* name, string color, int age): Pet(name, color, age){
	/*setname(name);
	setAge(age);
	setColor(color);*/
	cout << "Dog constructor called" << endl;
}
Dog::~Dog() {
	// TODO Auto-generated destructor stub
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound(){
	cout<<"Wang Wang!!!"<<endl;
}
void Dog::printName(){
	cout<<"My dog's name is: "<<getName()<<endl;
}
void Dog::eat(){
	cout<<"eat Meat!!!"<<endl;
}

void Dog::print(std::ostream& os) const {
    os << "[Dog] Name: " << getName()
       << ", Color: " << getColor()
       << ", Age: " << getAge();
}
