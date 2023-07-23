#pragma once
class Element
{
public:
	bool guessed = false;
	char letter = 'A';
	Element() {}
	Element(char character) {
		letter = character;
	}
};

