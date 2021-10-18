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
	const string word;
	time_t start, end;
	vector<char> opened_symbols;
	int lifes = 6;
public:
	Round(string word) : word{ word } {
		time(&start);
		logic();
	}
	~Round() {
	}
	void logic() {
		system("cls");
		if (check_win()) {
			win();
			return;
		}
		if (check_lose()) {
			lose();
			return;
		}
		update_field();
		ask_symb();
	}
	void update_field() {
		cout << "\tGuess the word:" << endl << " ";
		cout << "Current health: ";
		for (int i = 0; i < lifes; i++)
			cout << "* ";
		cout << endl;
		for (int i = 0; i < word.length(); i++) {
			if (is_opened(word[i])) cout << word[i] << " "; else cout << "_ ";
		}
		cout << endl;
		cout << endl;
	}
	bool is_opened(char ch) {
		for (int i = 0; i < opened_symbols.size(); i++) {
			if (ch == opened_symbols[i])
				return true;
		}
		return false;
	}
	bool check_win() {
		for(int i = 0; i < word.length(); i++)
			if (!is_opened(word[i])) {
				return false;
			}
		return true;
	}
	void win() {
		time(&end);
		cout << "\tHOOORAY!" << endl;
		cout << "It took you " << difftime(end, start) << " seconds to win!" << endl;
		cout << "Word was: " << word << endl;
		cout << "You have opened: ";
		for (int i = 0; i < opened_symbols.size(); i++) {
			cout << "'" << opened_symbols[i] << "', ";
		}
		cout << endl;
		cout << "You have lost only " << 6 - lifes << " lifes!" << endl;
		system("pause");
		system("cls");
	}
	void lose() {
		time(&end);
		cout << "\tWhoops!" << endl;
		cout << "It took you " << difftime(end, start) << " seconds to lose!" << endl;
		cout << "Word was: " << word << endl;
		cout << "You have opened: ";
		for (int i = 0; i < opened_symbols.size(); i++) {
			cout << "'" << opened_symbols[i] << "', ";
		}
		cout << endl;
		cout << "You have lost all your lifes!" << endl;
		system("pause");
		system("cls");
	}
	void check_lifes(char ch) {
		bool match = false;
		for (int i = 0; i < word.length(); i++) {
			if (ch == word[i]) match = true;
		}
		if (!match)
			lifes -= 1;
	}
	bool check_lose() {
		if (lifes == 0)
			return true;
		return false;
	}
	void ask_symb() {
		string ch;
		cout << "Enter symbol: ";
		cin >> ch;
		if (ch.length() > 1 || ((ch[0] < 'a' || ch[0] > 'z') && (ch[0] < 'A' || ch[0] > 'Z'))) {
			cout << "Something wrong!!!" << endl;
			system("pause");
			update_field();
		}
		for(int i = 0; i < opened_symbols.size(); i++)
			if (ch[0] == opened_symbols[i]) {
				cout << "Be careful! It was already!" << endl;
				system("pause");
				update_field();
			}
		opened_symbols.push_back(ch[0]);
		check_lifes(ch[0]);
		logic();
	}
};