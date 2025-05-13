/*
 * Cat.cpp
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#include "Cat.h"

Cat::Cat() {
	// TODO Auto-generated constructor stub
}
Cat::Cat(const char* name, string color, int age): Pet(name, color, age){
	cout << "Cat constructor called" << endl;
}

Cat::~Cat() {
	// TODO Auto-generated destructor stub
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound(){
	cout<<"Miao Miao!!!"<<endl;
}
void Cat::printName(){
	cout<<"My Cat's name is: "<<getName()<<endl;
}
void Cat::eat(){
	cout<<"eat Fish!!!"<<endl;
}
void Cat::print(std::ostream& os) const {
    os << "[Cat] Name: " << getName()
       << ", Color: " << getColor()
       << ", Age: " << getAge();
}
