// 1_3_Payroll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>

int main()
{   
    const unsigned short maxDays = 14;
    const float tax = 0.1f;
    unsigned int uCount = 0; // get days worked

    string name; // get name

    unsigned short hours[maxDays]; // get days hours
    float fGrossPay = 0; // - calc - total hours * wage
    float netPay = 0; // - calc - gross * (tax * gross)
    float fWage = 0; // get wage




    cout << "Enter your name\n";
    cin >> name;
    cout << "Enter days worked\n";
    cin >> daysWorked;
    cout << "Enter wage\n";
    cin >> fWage;

    for (int i = 0; i < uCount; i++) {
        cout << "\nEnter Day " << i+1 << " hours\n";
        cin >> hours[i];
        fGrossPay += hours[i];
    }
    fGrossPay *= fWage;

    netPay = fGrossPay * (1 - tax);
    cout << "\n Net Pay: " << netPay;


}

