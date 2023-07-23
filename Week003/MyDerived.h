#pragma once
#include "MyBase.h"
class MyDerived : public MyBase
{
public:
	int addSomething(int initVal);
	int subSomething(int initVal) {
		return initVal - 42;
	}
};

