// 2_1_DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
    const unsigned short MAXEMP = 20;
    Employee workers[MAXEMP];
    unsigned short numEmployees = 0;

    cout << "\n Please enter number of employees. (Max 20) \n";
    cin >> numEmployees;
    if (numEmployees > MAXEMP) {
        numEmployees = MAXEMP;
    }
    for (int i = 0; i < numEmployees; i++) {
        // call read for each employee
        workers[i].Read();
    }
    cout << "\n\n\n";
    for (int i = 0; i < numEmployees; i++) {
        // call write for each employee
        workers[i].Write();
    }










    //DEMO - workers[0].age = 23;


    //DEMO - Employee* empPtr = new Employee(); //Heap - new = on the heap
    //DEMO - //empPtr = &workers[0];
    //DEMO - empPtr->age = 42;

    //DEMO - void* ptr = malloc(20);
    //DEMO - int* intPtr = new int; //Heap

    //DEMO - *intPtr = 42;
    //DEMO - printf("\n hex %00.x ", *intPtr);
    //DEMO - printf("\n hex %00.x ", *intPtr+1);
    //do stuff

    //DEMO - cout << "\n\nSize: " << sizeof(Employee);
    //DEMO - delete empPtr;

    //will need this - how do I know that, answer
    //DEMO - cout << "\n Size 1: " << (sizeof(workers) / sizeof(workers[0]));
    //DEMO - cout << "\n Size 2: " << size(workers);



}
