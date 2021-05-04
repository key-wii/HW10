// Participants: Gabriela Lopez, Andrew Thompson, Long Duong, Gia Minh Hoang, Duyen Tran, Thien Vu, Christopher Gomez and Lincoln Nguyen
// Date: 05-4-21
// Description: Chapter 10 Solution

#include "input.h"
#include "driver1.h"
#include "driver2.h"
#include "driver3.h"
#include <iostream>
using namespace std;

//Precondition: N/A
//Postcondition: Prints menu and returns user int option selected
int menuOption();

// driver function/program
int main()
{
	do
	{
		switch (menuOption())
		{
		case 0:  exit(0);
		case 1:  system("cls"); option1(); break;
		case 2:  system("cls"); option2(); break;
		case 3:  system("cls"); option3(); break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		cout << "\n\t";
		system("pause");
	} while (true);
	return 0;

}

int menuOption()
{
	system("cls");
	cout << '\n';
	cout << '\t' << char(201) << string(43, char(205)) << char(187) << '\n';
	cout << '\t' << char(186) << "      \t    CMPR131: Chapter 9              " << char(186) << '\n';
	cout << '\t' << char(186) << "      \t\t  Made by:                  " << char(186) << '\n';
	cout << '\t' << char(186) << "   - Gabriela Lopez\t- Andrew Thompson   " << char(186) << '\n';
	cout << '\t' << char(186) << "   - Lincoln Nguyen\t- Long Duong        " << char(186) << '\n';
	cout << '\t' << char(186) << "   - Christopher Gomez\t- Gia Minh Hoang    " << char(186) << '\n';
	cout << '\t' << char(186) << "   - Duyen Tran\t- Thien Vu          " << char(186) << '\n';
	cout << "\t" << char(204) << string(43, char(205)) << char(185) << "\n";
	cout << "\t" << char(186) << "   1: binary_tree_node                     " << char(186) << "\n";
	cout << "\t" << char(186) << "   2: BinaryTree                           " << char(186) << "\n";
	cout << "\t" << char(186) << "   3: Animal Guessing Game                 " << char(186) << "\n";
	cout << "\t" << char(199) << string(43, char(196)) << char(182) << "\n";
	cout << "\t" << char(186) << "   0: Exit                                 " << char(186) << "\n";
	cout << "\t" << char(200) << string(43, char(205)) << char(188) << "\n";

	int option = inputInteger("\t    Option: ", 0, 3);
	cin.clear();
	return option;
}