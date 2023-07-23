// Week001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Week_1 Hello World!\n\n";


    int iVal1 = -1;
    short sVal2 = 3;
    long lVal = 1911789;
    int iVal3 = 8;
    float fVal = 23;
    char cVal = 'c';


    //iVal1 = sVal2;

    std::cout << "iVal1: " << iVal1 << " " << &iVal1;
    std::cout << "\nsVal2: " << sVal2 << " " << &sVal2;

    std::cout << "\n\n" << (&iVal1 - &iVal3) << "\n";

    std::cout << "\n Size of character: " << sizeof(cVal);
    std::cout << "\n Size of short: " << sizeof(sVal2);
    std::cout << "\n Size of int: " << sizeof(iVal1);

    int* iPtr = NULL;
    iPtr = &iVal1;

    std::cout << "\nvalue of ptr variable: " << iPtr << "\n\n";
    std::cout << "\n iPtr address: " << &iPtr;
    std::cout << "\n iPtr address size: " << sizeof(iPtr) << "\n";

    std::cout << "\n value iPtr points to is: " << *(iPtr + 20);

    //heap memory
    char* chTemp = NULL;
    chTemp = (char*)malloc(20);
    memset(chTemp, '\0', 20); // 0 & NULL = '\0' in this version of C++;
    //do stuff then free it up
    free(chTemp);
    chTemp = NULL; // good practice

    std::cout << "\nProgram Over";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
