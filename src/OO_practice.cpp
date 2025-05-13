//============================================================================
// Name        : OO_practice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Pig.h"
#include "PetManager.h"

void print_your_pet_Info(Pet* ppn){
	ppn->printName();
	cout<<"And it's age is: "<<ppn->getAge()<<", it's color is: "<<ppn->getColor()<<endl;
	ppn->eat();

	cout<<endl;
}
void constructor_overload(){
	vector<Pet*> pet_group(3);
	pet_group[0] = new Cat("April", "red", 6);
	pet_group[1] = new Dog("May", "yellow", 7);
	pet_group[2] = new Pig("June", "green", 6);


	print_your_pet_Info(pet_group[0]);
	print_your_pet_Info(pet_group[1]);
	print_your_pet_Info(pet_group[2]);

	for(auto pet:pet_group)
		delete pet;
}
void destructor_pratice(){
	Pet* p1 = new Dog("A", "red", 2);
	delete p1;
/* out put::
    Pet constructor called
	Dog constructor called
	Dog destructor called
	Pet destructor called
 */
}

void copy_constructor(){
	Pet p1("Asher", "Brown", 5);
	Pet p2 = p1;
}
void copy_assignment_operator(){
	Pet p1("Asher", "Brown", 5);
	Pet p2("Lulu", "White", 2);
	p2 = p1;
}
void move_constructor(){
	Pet p1("Rex", "Brown", 5);
	Pet p2 = move(p1);   //move constructor
	cout<<p1.getName()<<endl;

	Pet p3("Alice", "White", 2);
	p3 = move(p2);       //move assignment
}
void friend_opera(){
	Pet p1("Asher", "Black", 3);
	cout << p1 << endl;

	Pet* d1 = new Dog("Alice", "White", 2);
	cout<< *d1 <<endl;
}
void pet_manager(){
	/*PetManager mgr;
	mgr.addPet(make_unique<Dog>("Asher", "Black", 3));
	mgr.addPet(make_unique<Cat>("Mimi", "White", 2));
	mgr.printAll();
	mgr.clearAll();*/

	PetManager mgr1;
	mgr1.addPet(make_unique<Dog>("Alpha", "Black", 3));
	mgr1.addPet(make_unique<Cat>("Beta", "White", 2));
	mgr1.printAll();
	mgr1.renamePet("Beta", "Gamma");
	mgr1.removePetByName("Alpha");
	mgr1.printAll();
}
void pet_manager_readFile(){
	PetManager mgr;
	mgr.addPet(make_unique<Dog>("Max", "Black", 4));
	mgr.addPet(make_unique<Cat>("Mimi", "White", 2));

	mgr.saveToFile("pets.txt");

	PetManager mgr2;
	mgr2.loadFromFile("pets.txt");
}
void pet_manager_menu();

int main() {
	//constructor_overload();
	//destructor_pratice();
	//copy_constructor();
	//copy_assignment_operator();
	//move_constructor();
	//friend_opera();
	//pet_manager();
	//pet_manager_readFile();
	pet_manager_menu();

	cout<<"finish main()!"<<endl;
	return 0;
}

void pet_manager_menu() {
    PetManager mgr;
    int choice;
    string name, color, newName, type;
    int age;
    string filename;

    do {
        cout << "\n🐾 Pet Manager Menu:\n";
        cout << "1. Add Pet\n";
        cout << "2. Print All Pets\n";
        cout << "3. Remove Pet by Name\n";
        cout << "4. Rename Pet\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  // 清除換行符

        switch (choice) {
            case 1:
                cout << "Enter type (Dog/Cat/Pig): ";
                getline(cin, type);
                cout << "Name: "; getline(cin, name);
                cout << "Color: "; getline(cin, color);
                cout << "Age: "; cin >> age; cin.ignore();
                if (type == "Dog") {
                    mgr.addPet(make_unique<Dog>(name.c_str(), color, age));
                } else if (type == "Cat") {
                    mgr.addPet(make_unique<Cat>(name.c_str(), color, age));
                } else if (type == "Pig") {
                    mgr.addPet(make_unique<Pig>(name.c_str(), color, age));
                } else {
                    cout << "❌ Invalid pet type.\n";
                }
                break;

            case 2:
                mgr.printAll();
                break;

            case 3:
                cout << "Enter name to remove: ";
                getline(cin, name);
                if (!mgr.removePetByName(name)) cout << "❌ Pet not found.\n";
                break;

            case 4:
                cout << "Old name: ";
                getline(cin, name);
                cout << "New name: ";
                getline(cin, newName);
                if (!mgr.renamePet(name, newName)) cout << "❌ Pet not found.\n";
                break;

            case 5:
                cout << "Enter filename: ";
                getline(cin, filename);
                mgr.saveToFile(filename) ? cout << "✅ Saved.\n" : cout << "❌ Failed to save.\n";
                break;

            case 6:
                cout << "Enter filename: ";
                getline(cin, filename);
                mgr.loadFromFile(filename) ? cout << "✅ Loaded.\n" : cout << "❌ Failed to load.\n";
                break;

            case 0:
                cout << "👋 Bye!\n";
                break;

            default:
                cout << "❗ Invalid choice.\n";
        }

    } while (choice != 0);
}
