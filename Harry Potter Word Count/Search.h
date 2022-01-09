#pragma once
#include "Includes.h"
#include "Termcolor.h"

void search();
void getKeyWord(string& keyWord);
void getBook(string keyWord, bool& back, vector<bool>& book);
void searchBook(string keyWord, vector<bool>& book);

//---------------------------------------------------------------------------------------------------------------------

void search() {

	string keyWord{};
	bool back{false};

	vector<bool> book{ false, false, false, false, false, false, false, false, false };

	getKeyWord(keyWord);

	while (back == false)
	{
		getBook(keyWord, back, book);

		if (back == false)
			searchBook(keyWord, book);
	}
}

void getKeyWord(string& keyWord) {

	cout << "Search: ";
	cout << termcolor::bright_green;
	cin >> keyWord;
	cout << termcolor::reset;

	system("cls");
}

void getBook(string keyWord, bool& back, vector<bool>& book) {

	int select{};
	string selectIcon{ "->" };
	bool chosen{ false };

	while (chosen == false)
	{
		cout << "Search: " << termcolor::bright_green << keyWord << termcolor::reset << endl << endl;

		if (select == 0)
			cout << selectIcon << " | Harry Potter [1] and the Philosopher's Stone" << endl;
		else
			cout << " | Harry Potter [1] and the Philosopher's Stone" << endl;

		if (select == 1)
			cout << selectIcon << " | Harry Potter [2] and the Chamber of Secrets" << endl;
		else
			cout << " | Harry Potter [2] and the Chamber of Secrets" << endl;

		if (select == 2)
			cout << selectIcon << " | Harry Potter [3] and the Prisoner of Azkaban" << endl;
		else
			cout << " | Harry Potter [3] and the Prisoner of Azkaban" << endl;

		if (select == 3)
			cout << selectIcon << " | Harry Potter [4] and the Goblet of Fire" << endl;
		else
			cout << " | Harry Potter [4] and the Goblet of Fire" << endl;

		if (select == 4)
			cout << selectIcon << " | Harry Potter [5] and the Order of the Phoenix" << endl;
		else
			cout << " | Harry Potter [5] and the Order of the Phoenix" << endl;

		if (select == 5)
			cout << selectIcon << " | Harry Potter [6] and the Half-Blood Prince" << endl;
		else
			cout << " | Harry Potter [6] and the Half-Blood Prince" << endl;

		if (select == 6)
			cout << selectIcon << " | Harry Potter [7] and the Deathly Hallows" << endl;
		else
			cout << " | Harry Potter [7] and the Deathly Hallows" << endl;

		if (select == 7)
			cout << selectIcon << " | All Books" << endl;
		else
			cout << " | All Books" << endl;

		char menuSelect = tolower(_getch());
		switch (menuSelect)
		{
		case 'w':
			select -= 1;
			break;
		case 's':
			select += 1;
			break;
		case 13:
			if (select == 0)
				book[0] = true;
			else if (select == 1)
				book[1] = true;
			else if (select == 2)
				book[2] = true;
			else if (select == 3)
				book[3] = true;
			else if (select == 4)
				book[4] = true;
			else if (select == 5)
				book[5] = true;
			else if (select == 6)
				book[6] = true;
			else if (select == 7)
				book[7] = true;
			else
				back = true;

			chosen = true;
			break;
		case 8:
			chosen = true;
			back = true;
			break;
		default:
			break;
		}

		if (select < 0)
			select = 7;
		if (select > 7)
			select = 0;

		system("cls");
	}

	chosen = false;

}

void searchBook(string keyWord, vector<bool>& book) {

	string buff{};
	string substring{};

	vector<string> bookName{"a", "b", "c", "d", "e", "f", "g", "h"};

	vector<string> lines{};
	vector<vector<string>> linesAll(7, vector<string>(7));
	vector<string> words{};
	int wordCounter{};
	int wordCountTemp{};

	lines.clear();

	ofstream result("Result\\All Books - " + keyWord + ".txt", ios::in | ios::app | ios::out);

	//Get all lines from the book/books
	if (book[0] == true)
	{
		ifstream book1("Books\\Philosopher's stone.txt", ios::in);
		bookName[0] = "Philosopher's stone";

		while (book1)
		{
			book1 >> substring;
			lines.push_back(substring);
		}
		book1.close();
	}
	if (book[1] == true)
	{
		ifstream book2("Books\\Chamber of Secrets.txt", ios::in);
		bookName[0] = "Chamber of Secrets";

		while (book2)
		{
			book2 >> substring;
			lines.push_back(substring);
		}
		book2.close();
	}
	if (book[2] == true)
	{
		ifstream book3("Books\\Prisoner of Azkaban.txt", ios::in);
		bookName[0] = "Prisoner of Azkaban";

		while (book3)
		{
			book3 >> substring;
			lines.push_back(substring);
		}
		book3.close();
	}
	if (book[3] == true)
	{
		ifstream book4("Books\\Goblet of Fire.txt", ios::in);
		bookName[0] = "Goblet of Fire";

		while (book4)
		{
			book4 >> substring;
			lines.push_back(substring);
		}
		book4.close();
	}
	if (book[4] == true)
	{
		ifstream book5("Books\\The Order of the Phoenix.txt", ios::in);
		bookName[0] = "The Order of the Phoenix";

		while (book5)
		{
			book5 >> substring;
			lines.push_back(substring);
		}
		book5.close();
	}
	if (book[5] == true)
	{
		ifstream book6("Books\\The Half-Blood Prince.txt", ios::in);
		bookName[0] = "The Half-Blood Prince";

		while (book6)
		{
			book6 >> substring;
			lines.push_back(substring);
		}
		book6.close();
	}
	if (book[6] == true)
	{
		ifstream book7("Books\\The Deathly Hallows.txt", ios::in);
		bookName[0] = "The Deathly Hallows";

		while (book7)
		{
			book7 >> substring;
			lines.push_back(substring);
		}
		book7.close();
	}
	if (book[7] == true)
	{
		linesAll[0].clear();
		linesAll[1].clear();
		linesAll[2].clear();
		linesAll[3].clear();
		linesAll[4].clear();
		linesAll[5].clear();
		linesAll[6].clear();

		bookName[0] = "all 7 books";

		//Book 1
		ifstream book1("Books\\Philosopher's stone.txt", ios::in);
		bookName[1] = "Philosopher's stone";
		while (book1)
		{
			book1 >> substring;
			linesAll[0].push_back(substring);
		}
		book1.close();
		wordCountTemp = 0;

		for (size_t j = 0; j < linesAll[0].size(); j++)
		{
			if (linesAll[0][j] == keyWord)
			{
				wordCounter++;
				wordCountTemp++;
			}
		}
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[0 + 1] << ": " << termcolor::cyan << wordCountTemp << termcolor::reset << " times" << endl;
		result << keyWord << " mentioned in " << bookName[0 + 1] << ": " << wordCountTemp << " times" << endl;

		//Book 2
		ifstream book2("Books\\Chamber of Secrets.txt", ios::in);
		bookName[2] = "Chamber of Secrets";
		while (book2)
		{
			book2 >> substring;
			linesAll[1].push_back(substring);
		}
		book2.close();
		wordCountTemp = 0;

		for (size_t j = 0; j < linesAll[1].size(); j++)
		{
			if (linesAll[1][j] == keyWord)
			{
				wordCounter++;
				wordCountTemp++;
			}
		}
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[1 + 1] << ": " << termcolor::cyan << wordCountTemp << termcolor::reset << " times" << endl;
		result << keyWord << " mentioned in " << bookName[1 + 1] << ": " << wordCountTemp << " times" << endl;

		//Book 3
		ifstream book3("Books\\Prisoner of Azkaban.txt", ios::in);
		bookName[3] = "Prisoner of Azkaban";
		while (book3)
		{
			book3 >> substring;
			linesAll[2].push_back(substring);
		}
		book3.close();
		wordCountTemp = 0;

		for (size_t j = 0; j < linesAll[2].size(); j++)
		{
			if (linesAll[2][j] == keyWord)
			{
				wordCounter++;
				wordCountTemp++;
			}
		}
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[2 + 1] << ": " << termcolor::cyan << wordCountTemp << termcolor::reset << " times" << endl;
		result << keyWord << " mentioned in " << bookName[2 + 1] << ": " << wordCountTemp << " times" << endl;

		//Book 4
		ifstream book4("Books\\Goblet of Fire.txt", ios::in);
		bookName[4] = "Goblet of Fire";
		while (book4)
		{
			book4 >> substring;
			linesAll[3].push_back(substring);
		}
		book4.close();
		wordCountTemp = 0;

		for (size_t j = 0; j < linesAll[3].size(); j++)
		{
			if (linesAll[3][j] == keyWord)
			{
				wordCounter++;
				wordCountTemp++;
			}
		}
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[3 + 1] << ": " << termcolor::cyan << wordCountTemp << termcolor::reset << " times" << endl;
		result << keyWord << " mentioned in " << bookName[3 + 1] << ": " << wordCountTemp << " times" << endl;

		//Book 5
		ifstream book5("Books\\The Order of the Phoenix.txt", ios::in);
		bookName[5] = "The Order of the Phoenix";
		while (book5)
		{
			book5 >> substring;
			linesAll[4].push_back(substring);
		}
		book5.close();
		wordCountTemp = 0;

		for (size_t j = 0; j < linesAll[4].size(); j++)
		{
			if (linesAll[4][j] == keyWord)
			{
				wordCounter++;
				wordCountTemp++;
			}
		}
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[4 + 1] << ": " << termcolor::cyan << wordCountTemp << termcolor::reset << " times" << endl;
		result << keyWord << " mentioned in " << bookName[4 + 1] << ": " << wordCountTemp << " times" << endl;

		//Book 6
		ifstream book6("Books\\The Half-Blood Prince.txt", ios::in);
		bookName[6] = "The Half-Blood Prince";
		while (book6)
		{
			book6 >> substring;
			linesAll[5].push_back(substring);
		}
		book6.close();
		wordCountTemp = 0;

		for (size_t j = 0; j < linesAll[5].size(); j++)
		{
			if (linesAll[5][j] == keyWord)
			{
				wordCounter++;
				wordCountTemp++;
			}
		}
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[5 + 1] << ": " << termcolor::cyan << wordCountTemp << termcolor::reset << " times" << endl;
		result << keyWord << " mentioned in " << bookName[5 + 1] << ": " << wordCountTemp << " times" << endl;

		//Book 7
		ifstream book7("Books\\The Deathly Hallows.txt", ios::in);
		bookName[7] = "The Deathly Hallows";
		while (book7)
		{
			book7 >> substring;
			linesAll[6].push_back(substring);
		}
		book7.close();
		wordCountTemp = 0;

		for (size_t j = 0; j < linesAll[6].size(); j++)
		{
			if (linesAll[6][j] == keyWord)
			{
				wordCounter++;
				wordCountTemp++;
			}
		}
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[6 + 1] << ": " << termcolor::cyan << wordCountTemp << termcolor::reset << " times" << endl;
		result << keyWord << " mentioned in " << bookName[6 + 1] << ": " << wordCountTemp << " times" << endl;
}

	//Count Words and display them
	if (book[7] == true)
	{
		cout << endl;
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[0] << ": " << termcolor::cyan << wordCounter << termcolor::reset << " times" << endl;
		
		result << endl;
		result << keyWord << " mentioned in " << bookName[0] << ": " << wordCounter << " times" << endl;
	}
	else
	{
		for (size_t i = 0; i < lines.size(); i++)
		{
			if (lines[i] == keyWord)
				wordCounter++;
		}

		cout << endl;
		cout << termcolor::bright_green << keyWord << termcolor::reset << " mentioned in " << bookName[0] << ": " << termcolor::cyan << wordCounter << termcolor::reset << " times" << endl;
	}

	//Resets all chosen books
	book[0] = false;
	book[1] = false;
	book[2] = false;
	book[3] = false;
	book[4] = false;
	book[5] = false;
	book[6] = false;
	book[7] = false;
	book[8] = false;

	system("pause > 0");
	system("cls");
}