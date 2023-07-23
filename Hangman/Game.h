#pragma once
#include <iostream>
#include <vector>
#include "FileManager.h"
#include "UI.h"
#include "Element.h"
using namespace std;

class Game
{
public:
	FileManager* fm = new FileManager();
	vector<Element> elements;
	vector<char> guessedLetters;
	int wrongGuesses = 0;
	const bool debugMode = true;
	int maxGuesses = 6;

	Game() {
		srand(time(NULL));
		elements = wordToElement(generateWord());
		run();
	}
	~Game() {
		delete fm;
	}
private:
	void run() {
		bool playing = true;
		while (playing) {
			UI::displayGame(wrongGuesses, elements);
			char guess = NULL;
			while (guess == NULL) {
				guess = UI::getCharInput("Guess a Letter");
				for (char letter : guessedLetters) {
					if (letter == guess) {
						guess = NULL;
						UI::displayText("You Have Already Guessed This Letter! Guess Again");
					}
				}
			}
			
			bool allGuessed = true;
			bool badGuess = true;
			for (int i = 0; i < elements.size(); i++) {
				if (elements[i].letter == guess) {
					elements[i].guessed = true;
					badGuess = false;
				}
				if (!elements[i].guessed) allGuessed = false;
			}
			guessedLetters.push_back(guess);
			if (allGuessed) {
				playing = false;
				UI::displayEnd("You Won", elements);
			}
			if (badGuess) {
				wrongGuesses++;
				if (wrongGuesses >= maxGuesses) {
					playing = false;
					//UI::displayLoseAnimation();
					UI::displayEnd("You Lost", elements);
				}
			}

		}
	}


	string generateWord() {
		vector<string>* possibleWords = fm->getWords();
		int number = rand() % possibleWords->size();
		return possibleWords->at(number);
	}
	vector<Element> wordToElement(string word) {
		vector<Element> elements;
		for (int i = 0; i < word.length(); i++) {
			if(debugMode) cout << word[i];
			elements.push_back(*new Element(word[i]));
		}
		return elements;
	}
};

