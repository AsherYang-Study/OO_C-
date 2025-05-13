/*
 * PetManager.h
 *
 *  Created on: 2025年5月4日
 *      Author: YANG
 */

#ifndef PETMANAGER_H_
#define PETMANAGER_H_
#include <vector>
#include <memory>
#include "Pet.h"

class PetManager {
private:
    std::vector<unique_ptr<Pet>> pets;
public:
	PetManager();
	virtual ~PetManager();

	void addPet(unique_ptr<Pet> pet);
	void printAll() const;
	void clearAll();

	Pet* findPetByName(const std::string& name) const;
	bool removePetByName(const std::string& name);
	bool renamePet(const std::string& oldName, const string& newName);

	bool saveToFile(const std::string& filename) const;
	bool loadFromFile(const std::string& filename);
};

#endif /* PETMANAGER_H_ */
