/*
 * Pet.cpp
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#include "Pet.h"

/*   private   */
void Pet::init_data(const string& name, const string& color, int age) {
    this->name = name;
    this->color = color;
    this->age = age;
}

/*   public   */
Pet::Pet() {
	// TODO Auto-generated constructor stub
	name = " name is not set yet!!";
	color = "color is not set yet!!";
	age = 0;
}
Pet::Pet(const string& name, string color, int age){
	init_data(name, color, age);
	cout << "Pet constructor called" << endl;
}
//copy constructor
Pet::Pet(const Pet& other) {
/* if member have pointer like char* name
 * you should write the copy constructor by yourself
 * cause if you don't write system will generate the default copy constructor
 * and that only implement shallow copy (copy the pointer not the value)
 * so you do the destructor will cause delete two same pointer and crash
 *
 * */
	init_data(name, color, age);

    cout << "Pet copy constructor called" << endl;
}
// copy assignment operator
Pet& Pet::operator=(const Pet& other) {
    if (this == &other) return *this;  //prevent self-assignment

    //deep copy
    init_data(name, color, age);

    cout << "Pet operator= called" << endl;

    return *this;
}
// move constructor
Pet::Pet(Pet&& other){
	this->name = other.name;
	this->color = other.color;
	this->age = other.age;
	//move後, 東西會被搬走
	other.name = nullptr;
	cout << "Pet move constructor called" << endl;
}
// move assignment
Pet& Pet::operator=(Pet&& other){
	if(this==&other) return *this;

	this->name = other.name;
	this->color = other.color;
	this->age = other.age;
	other.name = nullptr;

	cout << "Pet move assignment called" << endl;
	return *this;
}
//operator<< + friend function
ostream& operator<<(ostream& os, const Pet& pet) {
    /*os << "[Pet Info] Name: ";
    if (pet.name) os << pet.name;
    else os << "(no name)";

    os << ", Color: " << pet.color
       << ", Age: " << pet.age;*/

	pet.print(os); //多型
    return os;
}

void Pet::print(std::ostream& os) const {
    os << "[Pet] Name: " << name
       << ", Color: " << color
       << ", Age: " << age;
}

Pet::~Pet() {
	// TODO Auto-generated destructor stub

	/* 子類別不需要再做一次delete
	 * 因為有virtual destructor所以都最終會走到父類別的解構涵式
	 *
	 * */
	cout << "Pet destructor called" << endl;
}

void Pet::eat(){
	cout<<" eat by default";
}
void Pet::walk_period(){
	cout<<" walk_period by default";
}
void Pet::makeSound(){
	cout<<" Pet sound not override yet";
}
void Pet::setname(const string& name){
	this->name = name;
}
void Pet::setAge(int age) {
	this->age = age;
}
void Pet::setColor(const string &color) {
	this->color = color;
}
int Pet::getAge() const{
	return age;
}
const string&  Pet::getColor() const{
	return color;
}
const string& Pet::getName() const{
	return this->name;
}
