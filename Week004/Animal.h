#pragma once
using namespace std;
#include <iostream>
#include <fstream>

class Animal
{
protected:
	string _name;
	unsigned int _lifespan;
	string _color;

public:
	enum class eType {Fish, Bird};


public:
	virtual eType getType() = 0; //Pure Virtual because of = 0 //acts like abstract in method and creation
	string getName() { return _name; }
	string getTypeStr();
	void setName(string val) { _name = val; }
	unsigned int getLifespan() { return _lifespan; }
	void setLifespan(unsigned int span) { _lifespan = span; }

	virtual void Read(std::ostream& ostr, std::istream& istr);
	virtual void Write(std::ostream& ostr);

	virtual void Read(std::ifstream& istr);
	virtual void Write(std::ofstream& ostr);




	// [5-3]
	friend bool operator == (const std::unique_ptr<Animal>& animal, const std::string& name) { return (name == animal->getName()); }
	friend bool operator == (const std::unique_ptr<Animal>& animal, Animal::eType type) { return (animal->getType() == type); }
	friend std::istream& operator >> (std::istream& istream, Animal& animal);
	friend std::ostream& operator << (Animal& animal, std::ostream& ostream);
	friend std::ifstream& operator >> (Animal& animal, std::ifstream& ifstream);
	friend std::ofstream& operator << (Animal& animal, std::ofstream& ofstream);
	





};

