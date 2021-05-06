#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "bintreenode.h"
#include "input.h"



void instructions();
void askAndMove(Binary_Tree_Node<string>*& currPtr);
Binary_Tree_Node<string>* beginTree(Binary_Tree_Node<string>*& currPtr, ifstream& file);
void learnNewAnimal(Binary_Tree_Node<string>*& currPtr);
void runGame(Binary_Tree_Node<string>* currPtr);
void playGame(Binary_Tree_Node<string>*& rootPtr, ifstream& file);
void option3();
void save(Binary_Tree_Node<string>*& rootPtr, ofstream& outfile);

Binary_Tree_Node<string>* beginTree(Binary_Tree_Node<string>*& currPtr, ifstream& file)
{

	string input;
	getline(file, input);
	char delim = input[0];


	input = input.substr(1, input.length() - 2);


	currPtr = new Binary_Tree_Node<string>(input);
	if (delim != '(')
	{
		beginTree(currPtr->left(), file);
		beginTree(currPtr->right(), file);
	}
	else
	{
		currPtr->left() = nullptr;
		currPtr->right() = nullptr;
	}

	return currPtr;

}
void askAndMove(Binary_Tree_Node<string>*& currPtr)
{
	cout << currPtr->data();
	if (inquire("Answer "))
		currPtr = currPtr->left();
	else
		currPtr = currPtr->right();

}
void learnNewAnimal(Binary_Tree_Node<string>*& leafPtr)
{
	string guess;
	string correct;
	string newQuestion;

	guess = leafPtr->data();
	cout << "Alright, I give. What was your animal?\n";
	getline(cin, correct);
	cout << "Enter a new yes or no question that will distinguish a " << correct << " from a " << guess << ".\n";
	getline(cin, newQuestion);

	leafPtr->setData(newQuestion);
	cout << "As a " << correct << ", " << newQuestion << '\n';
	if (inquire("Answer "))
	{
		leafPtr->setLeft(new Binary_Tree_Node<string>(correct));
		leafPtr->setRight(new Binary_Tree_Node<string>(guess));
	}
	else
	{
		leafPtr->setRight(new Binary_Tree_Node<string>(correct));
		leafPtr->setLeft(new Binary_Tree_Node<string>(guess));

	}
}

void runGame(Binary_Tree_Node<string>* currPtr)
{
	cout << "Think of an animal, then press the return key";
	eatLine();
	while (!currPtr->isLeaf())
		askAndMove(currPtr);

	cout << "My guess is " + currPtr->data() << ".\n";
	if (!inquire("Am I correct? "))
		learnNewAnimal(currPtr);
	else
		cout << "\nAh, I knew it was that from the start!\n";




}
void instructions()
{

	cout << "\tThis is a learning version of twenty questions : one that not only plays the game, but learns new\n";
	cout << "\tobjects when it loses.\n";

}
void playGame(Binary_Tree_Node<string>*& rootPtr, ifstream& file)
{
	if (rootPtr->left() != nullptr)
		deleteTree<string>(rootPtr);
	rootPtr = new Binary_Tree_Node<string>();
	rootPtr = beginTree(rootPtr, file);
	//do
	runGame(rootPtr);
	//while (inquire("want to play again?"));
	//cout << "Thanks for teaching me more about animals!\n";
	return;
}
void save(Binary_Tree_Node<string>*& rootPtr, ofstream& outfile)
{
	if (rootPtr != nullptr)
	{
		if (!rootPtr->isLeaf())
			outfile << '[' + rootPtr->data() + ']' << '\n';
		else
			outfile << '(' + rootPtr->data() + ')' << '\n';
		save(rootPtr->left(), outfile);
		save(rootPtr->right(), outfile);
	}

}
