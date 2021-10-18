#pragma once
#include "Round.h"
#define DEBUG
using namespace std;
class Game {
private:
	bool show_words = false;
	const string filename = "Words.txt";
	vector<string> words;
public:
	Game() {
		init_words();
		menu();
	}
	~Game() {

	}
	void menu() {
		int ch;
		cout << "\tWelcome!" << endl;
		cout << "[1] Start game" << endl;
		cout << "[2] Add word" << endl;
		cout << "[3] Delete word" << endl;
#ifdef DEBUG
		cout << "[4] Change visibility of words" << endl;
#endif // DEBUG
#ifndef DEBUG
		cout << endl;
#endif // !DEBUG

		cout << "[5] Exit" << endl;
		if (show_words == true)
			list_of_words();
		ch = _getch();
		switch (ch)
		{
		case '1': {
			system("cls");
			Round* round = new Round(choose_word());
			delete round;
			menu(); }
		case '2':
			add_word();
			system("cls");
			menu();
		case '3':
			delete_word();
			system("cls");
			menu();
#ifdef DEBUG
		case '4':
			if (show_words == false)
				show_words = true;
			else
				show_words = false;
			system("cls");
			menu();
#endif // DEBUG

		case '5':
			cout << "Thank you for playing this game!" << endl;
			system("pause");
			exit(0);
		default:
			system("cls");
			menu();
		}
	}
	string choose_word() {
		return words[rand() % words.size()];
	}
	void init_words() {
		ifstream fin(filename);
		string temp;
		while (fin >> temp)
		{
			for (int i = 0; i < temp.length(); i++) {
				temp[i] = temp[i] - '0';
			}
			words.push_back(temp);
		}
		fin.close();
	}
	void add_word() {
		string temp;
		ofstream of(filename, ios::app);
		cout << "Enter added word(or 0 to exit): "; cin >> temp;
		if (temp == "0")
			return;
		for (int i = 0; i < temp.length(); i++) {
			if (temp.length() < 2 || ((temp[i] < 'a' || temp[i] > 'z') && (temp[i] < 'A' || temp[i] > 'Z'))) {
				cout << "Something wrong!!!" << endl;
				system("pause");
				system("cls");
				menu();
			}
		}
		words.push_back(temp);
		for (int i = 0; i < temp.length(); i++)
			temp[i] = temp[i] + '0';
		of << temp << " ";
		of.close();
	}
	void delete_word() {
		fstream io(filename);
		string str, str_words;
		getline(io, str_words);
		cout << "Enter deleted word(or 0 to exit): "; cin >> str;
		words.erase(remove(words.begin(), words.end(), str), words.end());
		for (int i = 0; i < str.length(); i++)
			str[i] = str[i] + '0';
		if (str == "0")
			return;
		int pos = str_words.find(str);
		if (pos == (int)string::npos)
		{
			cerr << "Can`t find!" << endl;
			return;
		}
		str_words.erase(pos, str.size());
		io.close();
		io.open(filename, ios::out);
		io << str_words;
		io.close();
	}
	void list_of_words() {
		cout << "Words: " << endl;
		for (int i = 0; i < words.size(); i++)
				cout << words[i] << ", ";
		cout << endl;
	}
	void clear_words() {
		ofstream fout(filename, ios::trunc);
		fout.close();
	}
};