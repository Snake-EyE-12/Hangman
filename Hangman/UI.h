#pragma once
#include <iostream>
#include "Element.h"
#include <vector>
using namespace std;
class UI
{
public:
	static void displayText(string text) {
		cout << " " << text << endl;
	}
	static void displayText(char text) {
		cout << " " << text << endl;
	}
	static void displayEnd(string text, vector<Element> word) {
		UI::displayText(text);
		string message;
		for (Element e : word) {
			message += e.letter;
		}
		//displayText("The Word Was " + message + "\n");
	}
	static void displayLoseAnimation() {

		displayText("\n\n\n +-------------+");
		displayText("|             |");
		displayText("|             o");
		displayText("|            /|\\");
		displayText("|             /\\");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|\n\n\n");

		displayText("\n\n\n +-------------+");
		displayText("|             |");
		displayText("|");
		displayText("|             o");
		displayText("|            /|\\");
		displayText("|             /\\");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|\n\n\n");

		displayText("\n\n\n +-------------+");
		displayText("|             |");
		displayText("|");
		displayText("|");
		displayText("|             o");
		displayText("|            /|\\");
		displayText("|             /\\");
		displayText("|");
		displayText("|");
		displayText("|\n\n\n");

		displayText("\n\n\n +-------------+");
		displayText("|             |");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|             o");
		displayText("|            /|\\");
		displayText("|             /\\");
		displayText("|");
		displayText("|\n\n\n");

		displayText("\n\n\n +-------------+");
		displayText("|             |");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|             o");
		displayText("|            /|\\");
		displayText("|             /\\");
		displayText("|\n\n\n");
	}
	static int getInputPlayAgain(string text) {
		displayText(text);
		displayText("1. Yes");
		displayText("2. No");
		return getIntInput(1, 2);
	}
	static char getCharInput(string text) {
		displayText(text);
		char selection = INT16_MIN;
		while (selection < 'a' || selection > 'z' || isdigit(selection)) {
			displayText("Selection:");
			cin >> selection;
		}
		return selection;
	}

	static void displayGame(int incorrectGuesses, vector<Element> word) {
		displayText("\n\n\n +-------------+");
		displayText("|             |");
		if (incorrectGuesses >= 1) displayText("|             o");
		else displayText("|");
		if (incorrectGuesses >= 4) displayText("|            /|\\");
		else if (incorrectGuesses >= 3) displayText("|            /|");
		else if (incorrectGuesses >= 2) displayText("|             |");
		else displayText("|");
		if (incorrectGuesses >= 6) displayText("|             /\\");
		else if (incorrectGuesses >= 5) displayText("|            /");
		else displayText("|");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|");
		displayText("|\n\n\n");

		string text = "   ";
		for (Element element : word) {
			//cout << element.guessed;
			if (element.guessed) {
				text += element.letter;
				text += " ";
			}
			else {
				text += "_ ";
			}
		}
		displayText(text);
	}


private:
	static int getIntInput(int min, int max) {
		int selection = INT16_MIN;
		while (selection < min || selection > max) {
			displayText("Selection:");
			cin >> selection;
		}
		return selection;
	}
	
};

