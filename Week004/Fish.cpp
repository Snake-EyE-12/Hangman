#include "Fish.h"

void Fish::Read(std::ostream& ostr, std::istream& istr) {
	Animal::Read(ostr, istr);
	ostr << "\n Enter Fins\n";
	istr >> this->fins;
	ostr << "\n Enter Teeth\n";
	istr >> this->teeth;
	ostr << "\n Enter Habitat\n";
	istr >> this->habitat;
}
void Fish::Write(std::ostream& ostr) {
	ostr << "\n ---------------------------------\n";
	Animal::Write(ostr);
	ostr << "\n Fins: " << this->fins;
	ostr << "\n Teeth: " << this->teeth;
	ostr << "\n Habitat: " << this->habitat;
	
}
void Fish::Read(std::ifstream& istr) {
	Animal::Read(istr);
	istr >> this->fins;
	istr >> this->teeth;
	istr >> this->habitat;
}
void Fish::Write(std::ofstream& ostr) {
	Animal::Write(ostr);
	ostr << this->fins << endl;
	ostr << this->teeth << endl;
	ostr << this->habitat << endl;
}