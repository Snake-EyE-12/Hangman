#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
using namespace std;
class FileManager
{
public:
    const string wordFile = "Message.txt";


    vector<string>* getWords() {
		list<string>* words = new list<string>;

        fstream fileInput;

        fileInput.open(wordFile, ios::in);

        if (fileInput.is_open()) {
            string line;
            while (getline(fileInput, line)) {
                words->push_back(line);
            }
            fileInput.close();
        }
        vector<string>* allWords = new vector<string>(words->size());
        copy(words->begin(), words->end(), allWords->begin());
        return allWords;
    }
};

