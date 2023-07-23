#pragma once
#include "Animal.h"
class Fish : public Animal
{
protected:
	int fins;
	int teeth;
	string habitat;
public:
	eType getType() override { return eType::Fish; }
	void Read(std::ostream& ostr, std::istream& istr) override;
	void Write(std::ostream& ostr) override;

	void Read(std::ifstream& istr) override;
	void Write(std::ofstream& ostr) override;
};

