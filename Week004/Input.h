#pragma once
#include <iostream>
using namespace std;
class Input
{
public:
	int getUserInt(string prompt, unsigned short low, unsigned short high);
	int getUserInt(unsigned short low, unsigned short high);
};

