#include "Animal.h"


void Animal::Read(std::ostream& ostr, std::istream& istr) {
	ostr << "\n Enter Animal Name\n";
	istr >> this->_name;
	ostr << "\n Enter Animal Lifespan in Years\n";
	istr >> this->_lifespan;
}
void Animal::Write(std::ostream& ostr) {
	ostr << "\n Name: " << this->_name;
	ostr << "\n Lifespan: " << this->_lifespan;
	ostr << "\n Type: " << this->getTypeStr() << "\n\n";
}
void Animal::Read(std::ifstream& istr) {
	istr >> this->_name;
	istr >> this->_lifespan;
}
void Animal::Write(std::ofstream& ostr) {
	ostr << (int)this->getType() << std::endl; // Critically First
	ostr << this->_name << endl;
	ostr << this->_lifespan << endl;
}
std::istream& operator >> (std::istream& istr, Animal& animal) {
	animal.Read(std::cout, istr);
	return istr;
}
std::ostream& operator << (Animal& animal, std::ostream& ostr) {
	animal.Write(ostr);
	return ostr;
}
std::ifstream& operator >> (Animal& animal, std::ifstream& ifstream) {
	animal.Read(ifstream);
	return ifstream;
}
std::ofstream& operator << (Animal& animal, std::ofstream& ofstream) {
	animal.Write(ofstream);
	return ofstream;
}





















string Animal::getTypeStr() {
	switch (this->getType()) {
		case eType::Bird: {
			return "Bird";
		}
		case eType::Fish: {
			return "Fish";
		}
		default: {
			"Undef";
		}
	}
}