#include "Bird.h"

void Bird::Read(std::ostream& ostr, std::istream& istr) {
	Animal::Read(ostr, istr);
	ostr << "\n Enter Wingspan\n";
	istr >> this->wingspan;
	ostr << "\n Enter Egg Count\n";
	istr >> this->eggs;
}
void Bird::Write(std::ostream& ostr) {
	ostr << "\n ---------------------------------\n";
	Animal::Write(ostr);
	ostr << "\n Wingspand: " << this->wingspan;
	ostr << "\n Eggs: " << this->eggs;
	
}
void Bird::Read(std::ifstream& istr) {
	Animal::Read(istr);
	istr >> this->wingspan;
	istr >> this->eggs;
}
void Bird::Write(std::ofstream& ostr) {
	Animal::Write(ostr);
	ostr << this->wingspan << endl;
	ostr << this->eggs << endl;
}
