/*
 * PetManager.cpp
 *
 *  Created on: 2025年5月4日
 *      Author: YANG
 */

#include "PetManager.h"
#include "Dog.h"
#include "Cat.h"
#include "Pig.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

PetManager::PetManager() {
	// TODO Auto-generated constructor stub

}

PetManager::~PetManager() {
	// TODO Auto-generated destructor stub
	cout << "[PetManager] Destructor called.\n";
}

void PetManager::addPet(unique_ptr<Pet> pet) {
    pets.push_back(std::move(pet));
}

void PetManager::printAll() const {
    cout << "All Pets List:\n";
    for (const auto& pet : pets) {
        cout << " - " << *pet << endl;
    }
}

void PetManager::clearAll() {
    pets.clear();
    cout << "All pets removed.\n";
}

Pet* PetManager::findPetByName(const string& name) const {
    for (const auto& pet : pets) {
        if (pet && pet->getName() == name) {
            return pet.get();  // 傳回原始指標（非擁有權）
        }
    }
    return nullptr;
}

bool PetManager::removePetByName(const string& name) {
    auto it = std::remove_if(pets.begin(), pets.end(),
        [&](const unique_ptr<Pet>& pet) {
            return pet && pet->getName() == name;
        });

    if (it != pets.end()) {
        pets.erase(it, pets.end());
        return true;
    }
    return false;
}

bool PetManager::renamePet(const string& oldName, const string& newName) {
    Pet* target = findPetByName(oldName);
    if (target) {
        target->setname(newName);
        return true;
    }
    return false;
}

bool PetManager::saveToFile(const string& filename) const {
    ofstream ofs(filename);
    if (!ofs.is_open()) return false;

    for (const auto& pet : pets) {
        if (auto dog = dynamic_cast<Dog*>(pet.get())) {
            ofs << "Dog," << dog->getName() << "," << dog->getColor() << "," << dog->getAge() << endl;
        } else if (auto cat = dynamic_cast<Cat*>(pet.get())) {
            ofs << "Cat," << cat->getName() << "," << cat->getColor() << "," << cat->getAge() << endl;
        } else if (auto pig = dynamic_cast<Pig*>(pet.get())) {
            ofs << "Pig," << pig->getName() << "," << pig->getColor() << "," << pig->getAge() << endl;
        }
    }

    return true;
}

bool PetManager::loadFromFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs.is_open()) return false;

    clearAll();  // 清空舊資料

    string line;
    while (getline(ifs, line)) {
        istringstream iss(line);
        string type, name, color;
        string ageStr;

        getline(iss, type, ',');
        getline(iss, name, ',');
        getline(iss, color, ',');
        getline(iss, ageStr);
        int age = stoi(ageStr);

        if (type == "Dog") {
            addPet(make_unique<Dog>(name.c_str(), color, age));
        } else if (type == "Cat") {
            addPet(make_unique<Cat>(name.c_str(), color, age));
        } else if (type == "Pig") {
            addPet(make_unique<Pig>(name.c_str(), color, age));
        }
    }

    return true;
}
