/*
 * Pet.h
 *
 *  Created on: 2025年4月26日
 *      Author: YANG
 */

#ifndef PET_H_
#define PET_H_
#include <cstring>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
using std::ostream;

class Pet {
	string name;
	//char* name;
	string color;
	int age;

	//use this to set member clear, use deep copy
	void init_data(const string& name, const string& color, int age);
public:
	Pet();
	Pet(const string& name, string color, int age);

	Pet(const Pet& other); //for copy constructor

	// copy assignment operator
	Pet& operator=(const Pet& other);

	/* move constructor
	 * 如果沒有手動寫copy constructor / copy assignment
	 * 並且成員變數有支援mvoe
	 * 沒有要禁用move
	 * 系統就會自動生成 move constructor
	 * */
	Pet(Pet&& other);             // move constructor
	Pet& operator=(Pet&& other);  // move assignment

	//operator<< + friend function
	//friend : 讓非class成員的外部函式或類別也能存取 private/protected
	friend ostream& operator<<(ostream& os, const Pet& pet);

	//let ostream& operator<< can be 多型
	virtual void print(std::ostream& os) const;

	virtual ~Pet();
/*
 * if no use virtual only write ~Pet()
 * then if use father class declare child class
 * and you delete the father class pointer
 * your child class will not do destructor!!!
 *
 * */


	void walk_period();

	//add const back to function => this function can't modify the member variable
	int getAge() const;
	const string& getColor() const;
	const string& getName() const;

	void setname(const string& name);
	void setAge(int age);
	void setColor(const string &color);

	virtual void makeSound();

	virtual void printName(){
		cout<<"My Pet's name is: "<<this->name<<endl;
	}
	virtual void eat();


protected:

};

#endif /* PET_H_ */
