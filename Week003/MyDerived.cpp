#include "MyDerived.h"
int MyDerived::addSomething(int initVal) {
	return initVal + 100 + MyBase::addSomething(1);
}
