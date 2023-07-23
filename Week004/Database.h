#pragma once

#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include <list>

class Database
{
public:
	const string filename = "testfile.txt";
private:
	std::list<std::unique_ptr<Animal>> _animal;
public:
	std::unique_ptr<Animal> create(Animal::eType type);
	void add(std::unique_ptr<Animal>& animal);
	void displayAll(std::ostream& ostr);
	void displayName(std::ostream& ostr, string name);
	void displayType(std::ostream& ostr, Animal::eType type);
	void save(const string fileName);
	void load(const string fileName);
	void remove();
};

