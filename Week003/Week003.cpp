// Week003.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
    //int myInt = 5;			variable
    //int* intPtr = &myInt;		pointer
    //int& intRef = myInt;		reference




#include <iostream>
#include "MyConfig.h"
#include "MyDerived.h"
using namespace std;

struct Person
{
	char name[32];
	int id;
};

void Square(int& x) {
	x = x * x;
}
void Double(int* p) {
	*p = *p * 2;
}

int main()
{
	/////////////////////////////////////////////////////////////////////
	MyBase base;
	MyDerived derived;
	//cout << "\n\n\n" << base.addSomething(1) << "\n\n\n";
	/////////////////////////////////////////////////////////////////////
	//Config myConfig;
	//myConfig.
#pragma region ReferenceTest
	cout << "\n\n Reference Test:\n";
	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	int myInt = 9;
	// declare a int reference and set it to the int variable above
	int& myIntRef = myInt;
	// output the int variable
	cout << myInt << "\n";
	// set the int reference to some number
	myIntRef = 5;
	// output the int variable
	cout << myInt << "\n";
	// what happened to the int variable when the reference was changed? (insert answer)
	//______________________________________________________________________________
			//---------      The int value changed to what the reference was set to
	// _____________________________________________________________________________
	// output the address of the int variable
	cout << &myInt << "\n";
	// output the address of the int reference
	cout << &myIntRef << "\n";
	// are the addresses the same or different? (insert answer)
	//______________________________________________________________________________
			//---------      They are the same addresses
	// _____________________________________________________________________________
	#pragma endregion

#pragma region ReferenceParameter
	cout << "\n\n Reference Parameter:\n";
	// ** REFERENCE PARAMETER **
	// 
	// create a function above main() called Square that takes in an int parameter
		// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
		// call the Square function with the int variable created in the REFERENCE section
	Square(myInt);
		// output the int variable to the console
	cout << myInt << "\n";
		// !! notice how the variable has not changed, this is because we only passed the value to the function !!
		// change the Square function to take a int reference
		// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
		// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
		// ** POINTER VARIABLE **
		//
		// declare an int pointer, set it to nullptr (it points to nothing)
	int* myIntPtr = nullptr;
		// set the int pointer to the address of the int variable created in the REFERENCE section
	myIntPtr = &myInt;
		// output the value of the pointer
	cout << myIntPtr << "\n";
		// what is this address that the pointer is pointing to? (insert answer)
	//______________________________________________________________________________
			//---------      The int memory location
	// _____________________________________________________________________________

		// output the value of the object the pointer is pointing to (dereference the pointer)
	cout << *myIntPtr  << "\n";
	#pragma endregion

#pragma region PointerParameter
	cout << "\n\n Pointer Parameter:\n";
		// ** POINTER PARAMETER **
		//
		// create a function above main() called Double that takes in an int pointer parameter
		// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
		// !! make sure to dereference the pointer to set the value and not set the address !!
		// call the Double function with the pointer created in the POINTER VARIABLE section
	Double(myIntPtr);
		// output the dereference pointer
	cout << *myIntPtr << "\n";
		// output the int variable created in the REFERENCE section
	cout << myInt << "\n";
		// did the int variable's value change when using the pointer?
	//______________________________________________________________________________
			//---------      Yes
	// _____________________________________________________________________________
	#pragma endregion

#pragma region AllocationDeallocation
	cout << "\n\n Allocation:\n";
		// ** ALLOCATION/DEALLOCATION **
		//
		// create an int pointer that points at an int allocated on the heap, set the allocated int value to some number
	int* Int2Ptr = new int;
	*Int2Ptr = 4;
		// output the pointer value, this should be the address of the int allocated on the heap
	cout << Int2Ptr << "\n";
		// output the dereference pointer
	cout << *Int2Ptr << "\n";
		// deallocate the int pointer to free up the memory
	delete Int2Ptr;


		// create an int pointer that points at an array of ints allocated on the heap, the array size should be 4 - 6
	int size = 5;
	int* IntArray = new int[size];
		// use a for loop and set each int in the array to a random number (use => rand() % 10 to get a random number
	for (int i = 0; i < size; i++) {
		(IntArray[i]) = rand() % 10;
	}
		// use a for loop and output each of the ints in the array
	cout << "Array#: \n";
	for (int i = 0; i < size; i++) {
		cout << IntArray[i] << "\n";
	}
		// use a for loop and output the address of each of the ints in the array
	cout << "Array&: \n";
	for (int i = 0; i < size; i++) {
		cout << &IntArray[i] << "\n";
		
	}
		// deallocate the int pointer to free up the memory block (remember it's an array)
	delete IntArray;

	#pragma endregion


	cout << "\n\n Structure:\n";
		// ** STRUCTURE **
		// create a Person pointer that points at an array of Persons allocated on the heap, the array size should be 2
	int Psize = 2;
	Person* PersonPtr = new Person[Psize];
		// read in a name from the console and set it to the person name, do this for the id also, do this for both Persons
	for (int i = 0; i < Psize; i++) {
		cout << "\n Enter Name:\n";
		cin >> PersonPtr[i].name;
		cout << "\n Enter ID:\n";
		cin >> PersonPtr[i].id;
	}
		// use a for loop and output the name and id of each person in the array
	for (int i = 0; i < Psize; i++) {
		cout << "\n Name: " << PersonPtr[i].name << " ID: " << PersonPtr[i].id;
	}
		// deallocate the person pointer to free up the memory block (remember it's an array)
	delete PersonPtr;

}