// Week004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>
#include "Input.h";
#include "Animal.h"
#include "Database.h"

int main()
{
    Input input;
    std::unique_ptr<Animal> animal;
    Database db;
    cout << "Hello Week 4!\n";

    int iMenu = 0;
    while (iMenu < 8) {
        cout << "\n Enter a menu option: ";
        cout << "\n 1. Add an Animal";
        cout << "\n 2. Display all Animals";
        cout << "\n 3. Display by Name";
        cout << "\n 4. Display by Type";
        cout << "\n 5. Remove All";
        cout << "\n 6. Load From File";
        cout << "\n 7. Save To File";
        cout << "\n 8. Quit\n";

        iMenu = input.getUserInt(" Selection: \n", 1, 8);
        int iType = 0;
        switch (iMenu) {
        case 1: {
            iType = 0;
            cout << "\n 1) Fish";
            cout << "\n 2) Bird \n";
            iType = input.getUserInt(1, 2);
            switch (iType) {
            case 1:
                animal = db.create(Animal::eType::Fish);
                break;
            case 2:
                animal = db.create(Animal::eType::Bird);
                break;
            }
            animal->Read(cout, cin);
            db.add(animal);
            break;
        }
        case 2: {
            db.displayAll(cout);
            break;
        }
        case 3: {
            string name;
            cout << "\n Enter Name: ";
            cin >> name;
            db.displayName(cout, name);
            break;
        }
        case 4: {
            iType = 0;
            cout << "\n 1) Fish";
            cout << "\n 2) Bird \n";
            iType = input.getUserInt(1, 2);
            switch (iType) {
            case 1:
                db.displayType(cout, Animal::eType::Fish);
                break;
            case 2:
                db.displayType(cout, Animal::eType::Bird);
                break;
            }
            break;
        }
        case 5: {
            db.remove();
            break;
        }
        case 6: {
            db.load(db.filename);
            break;
        }
        case 7: {
            db.save(db.filename);
            break;
        }
        } //switch
    } //while
} //main
