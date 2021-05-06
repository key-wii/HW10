#pragma once
#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "bintreenode.h"
#include "input.h"



void instructions();
void askAndMove(Binary_Tree_Node<string>*& currPtr);
Binary_Tree_Node<string>* beginTree();
void learnNewAnimal(Binary_Tree_Node<string>* currPtr);
void runGame(Binary_Tree_Node<string>* currPtr);
void playGame(Binary_Tree_Node<string>*& rootPtr);
void option3();
void save(Binary_Tree_Node<string>*& rootPtr);

Binary_Tree_Node<string>* beginTree()
{
	ifstream file("animal.txt");
	if (!file.is_open())
	{
		cout << "Error! animal.txt now found!";
	}

	Binary_Tree_Node<string>* rootPtr;
	Binary_Tree_Node<string>* childPtr;
	const string rootQuestion("Is it  a mammal?");
	const string leftQuestion("Does it have stripes?");
	const string rightQuestion1("Is it a kind of bird?");
	const string rightQuestion2("Does it fly?");

	const string animal1("zebra");
	const string animal2("lion");
	const string animal3("eagle");
	const string animal4("penguin");
	const string animal5("Gila monster");
	rootPtr = new Binary_Tree_Node<string>(rootQuestion);
	childPtr = new Binary_Tree_Node<string>(leftQuestion);
	childPtr->setLeft(new Binary_Tree_Node<string>(animal1));
	childPtr->setRight(new Binary_Tree_Node<string>(animal2));
	rootPtr->setLeft(childPtr);
	childPtr = new Binary_Tree_Node<string>(rightQuestion1);
	childPtr->setLeft(new Binary_Tree_Node<string>(rightQuestion2));
	childPtr->setRight(new Binary_Tree_Node<string>(animal5));
	//Binary_Tree_Node<string>* holder = childPtr;
	childPtr = childPtr->left();
	childPtr->setLeft(new Binary_Tree_Node<string>(animal3));
	childPtr->setRight(new Binary_Tree_Node<string>(animal4));
	//childPtr = holder;
	rootPtr->setRight(childPtr);

	return rootPtr;
}
void askAndMove(Binary_Tree_Node<string>*& currPtr)
{
	cout << currPtr->data();
	if (inquire("Answer "))
		currPtr = currPtr->left();
	else
		currPtr = currPtr->right();

}
void learnNewAnimal(Binary_Tree_Node<string>* leafPtr)
{
	string guess;
	string correct;
	string newQuestion;

	guess = leafPtr->data();
	cout << "\nAlright, I give. What was your animal?\n";
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
	cout << "\nThink of an animal, then press the return key\n";
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
void playGame(Binary_Tree_Node<string>*& rootPtr)
{
	rootPtr = beginTree();
	//do
	runGame(rootPtr);
	//while (inquire("want to play again?"));
	//cout << "Thanks for teaching me more about animals!\n";
	return;
}
void save(Binary_Tree_Node<string>*& rootPtr)
{
	//file writing stuff
}
