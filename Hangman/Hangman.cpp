// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "UI.h"
#include "Game.h"
#include <iostream>
using namespace std;


static bool displayWord = true;

int main()
{

    UI::displayText("Hangman The Game");
    bool playing = true;
    while (playing) {
        Game* game = new Game();
        if (UI::getInputPlayAgain("Would You Like to Play Again?") == 2) {
            playing = false;
        }
        delete game;
    }



    /*for (int i = 0; i < 1000; i++) {
        cout << i << " " << (char)(i) << endl;
    }*/
}
