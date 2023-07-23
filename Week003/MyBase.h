#pragma once
#include "MyConfig.h"
class MyBase
{
public:
	virtual int addSomething(int initVal);
	Config conf; // Encapsulated
};

