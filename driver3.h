// Participants: 
// Date: 
// Description: file containing Drivers for option3
#pragma once

#include <iostream>
#include "bintreenode.h"
#include"animalGame.h"
using namespace std;

//Precondition: N/A
//Postcondition: contains driver for Animal Guessing Game
void option3()
{
	char cont = 'Y';
	char yes = 'Y', no = 'n';

	Binary_Tree_Node<string>* rootPtr;
	do {
		cout << "\t3: Animal Guessing Game\n";
		cout << '\t' << string(40, char(205)) << '\n';
		cout << "\n\n";

		instructions();
		cout << "\t Welcome to Animal Guessing Game\n";
		cout << '\t' << string(40, char(205)) << '\n';
		cout << "\t\t A: play\n";
		cout << "\t\t B: save the game file\n";
		cout << "\t\t x: return\n";
		cout << '\t' << string(40, char(205)) << '\n';
		char choice = inputChar("\n\t\tOption:", "ABXabx");

		switch (choice)
		{
		case('X'): return;
		case('A'): playGame(rootPtr); break;
		case('B'): save(rootPtr); break;
		}
	} while (true);
}