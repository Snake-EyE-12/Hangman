#include "Database.h"

std::unique_ptr<Animal> Database::create(Animal::eType type) {
	Animal* animal = nullptr;

	switch (type) {
	case Animal::eType::Bird:
		animal = new Bird;
		break;
	case Animal::eType::Fish:
		animal = new Fish;
		break;
	}
	return std::unique_ptr<Animal>{animal};

}
void Database::add(std::unique_ptr<Animal>& animal) {
	this->_animal.push_back(std::move(animal));
	cout << "\n ** List size: " << this->_animal.size() << "\n";

}
void Database::displayAll(std::ostream& ostr) {
	for (std::unique_ptr<Animal>& animal : this->_animal) {
		//animal->Write(ostr);
		ostr << animal;
	}
}
void Database::displayName(std::ostream& ostr, string name) {
	for (std::unique_ptr<Animal>& animal : this->_animal) {
		if (animal->getName()._Equal(name)) ostr << animal;//animal->Write(ostr);//
	}
}
void Database::displayType(std::ostream& ostr, Animal::eType type) {
	for (std::unique_ptr<Animal>& animal : this->_animal) {
		if (animal->getType() == type) ostr << animal;//animal->Write(ostr); //
	}
}
void Database::save(const string fileName) {
	std::ofstream output(fileName, std::ofstream::out | std::ofstream::app); // Bit Wise OR

	if (output.is_open()) {
		for (std::unique_ptr<Animal>& animal : this->_animal) {
			//animal->Write(output);
			output << animal;
		}
	}
	if (output.is_open()) {
		output.close();
	}
}
void Database::load(const string fileName) {
	int iType = 0;
	std::ifstream output(fileName);
	std::unique_ptr<Animal> animal;
	this->remove();
	if (output.is_open()) {
		while (!output.eof()) {
			output >> iType;
			if (output.fail()) break;
			animal = this->create(static_cast<Animal::eType>(iType));
			animal->Read(output);
			*animal >> output;
			//this->add(animal);
			/*
			switch (iType) {
			case 1: {
				animal = this->create(Animal::eType::Fish);
				break;
			}
			case 2: {
				animal = this->create(Animal::eType::Bird);
				break;
			}
			}
			*/
		}
	}
	if (output.is_open()) {
		output.close();
	}
}
void Database::remove() {
	_animal.clear();
}