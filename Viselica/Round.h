#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

class Round {
private:
	vector<bool> is_opened = { false };
	const string word;
	time_t start, end;
	vector<char> opened_symbols;
	int lifes = 6;
public:
	Round(string word) : word{ word } {
		time(&start);
		update_field();
	}
	void update_field() {
		system("cls");
		
		cout << "\tGuess the word:" << endl << " ";
		/*for (int i = 0; i < word.length(); i++) {
			if (is_opened[i])
				cout << word[i] << " ";
			else
				cout << "_ ";
		}*/
		bool opened = false;

		for (int i = 0; i < word.length(); i++) {
			for (int j = 0; j < opened_symbols.size(); j++) {
				if (word[i] == opened_symbols[j]) {
					opened = true;
				}
			}
			if (opened) {
				opened = false;
				cout << word[i] << " ";
			}
			else
				cout << "_ ";
		}
		cout << endl;
		ask_symb();
		//check_symbols();
	}
	/*void check_symbols() {
		for (int i = 0; i < word.length(); i++) {
			for (int j = 0; j < opened_symbols.size(); j++) {
				if (word[i] == opened_symbols[j]) {
					is_opened[i] = true;
					break;
				}
			}
		}
	}*/
	void ask_symb() {
		char ch;
		cout << "Enter symbol: "; cin >> ch;
		opened_symbols.push_back(ch);
		update_field();
	}
};