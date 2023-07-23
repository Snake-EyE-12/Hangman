#pragma once
class Employee
{

private:
    
    char name[32];
    float wage;
    int daysWorked;
    float hoursWorkedPerDay[7];
    float netPay;

public:
    Employee();
    void Read();
	void Write();
};

