#pragma once
#include "Animal.h"
class Bird : public Animal
{
protected:
	unsigned int eggs;
	float wingspan;
public:
	eType getType() override { return eType::Bird; }
	void Read(std::ostream& ostr, std::istream& istr) override;
	void Write(std::ostream& ostr) override;

	void Read(std::ifstream& istr) override;
	void Write(std::ofstream& ostr) override;
};

