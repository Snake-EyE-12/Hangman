#include "Employee.h"
#include <iostream>

using namespace std;

const float TAX = 0.1f;

Employee::Employee() {
	//constructor code
}
void Employee::Read() {
	//read code
    cout << "Enter your name\n";
    cin >> name;
    cout << "Enter days worked\n";
    cin >> daysWorked;
    cout << "Enter wage\n";
    cin >> wage;

    float fGrossPay = 0;
    int totalHours = 0;
    for (int i = 0; i < daysWorked; i++) {
        cout << "\nEnter Day " << i + 1 << " hours\n";
        int hours = 0;
        cin >> hours;
        totalHours += hours;
    }
    fGrossPay = wage * totalHours;

    netPay = fGrossPay * (1 - TAX);

}
void Employee::Write() {
    cout << "\n " << name << " earned: " << netPay;
}