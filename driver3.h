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
	//ifstream file("animal.txt");
	//if (!file.is_open())
	//{
	//	cout << "\nError! animal.txt not found!\n";
	//}
	Binary_Tree_Node<string>* rootPtr = new Binary_Tree_Node<string>();
	do {
		ifstream file("animal.txt");
		if (!file.is_open())
		{
			cout << "\nError! animal.txt not found!\n";
		}
		cout << "\t3: Animal Guessing Game\n";
		cout << '\t' << string(40, char(205)) << '\n';
		cout << "\n\n";

		instructions();
		cout << "\t Animal Guessing Game Menu:\n";
		cout << '\t' << string(40, char(205)) << '\n';
		cout << "\t\t 1: play\n";
		cout << "\t\t 2: Save to the game file\n";
		cout << "\t\t 0: return\n";
		cout << '\t' << string(40, char(205)) << '\n';
		char choice = inputInteger("\n\t\tOption:", 0, 2);

		switch (choice)
		{
		case(0): return;
		case(1):
		{
			ifstream infile("animal.txt");

			if (!infile.is_open())
				cout << "\nError! animal.txt not found!\n";
			playGame(rootPtr, infile);
			infile.close();
			break;

		}


		case(2):ofstream outfile("animal.txt"); save(rootPtr, outfile); outfile.close(); break;
		}



	} while (true);
}