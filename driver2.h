// Participants: Christopher
// Date: 5-6-21
// Description: file containing Drivers for option2
#pragma once

#include <iostream>
#include "BinaryTree.h"
using namespace std;

//Precondition: N/A
//Postcondition: contains driver for BinaryTree
void option2()
{
    int choice, findThis;
    BinaryTree twee;
    node* nod;
    do
    {
        cout << "\n";
        cout << "1. Insert a node/leaf\n";
        cout << "2. Delete a node/leaf\n";
        cout << "3. Count of nodes/leaves\n";
        cout << "4. Search a node/leaf\n";
        cout << "5. Pre-order traversal\n";
        cout << "6. In-order traversa\n";
        cout << "7. Post-order Traversal\n";
        //cout << "8. Delete the entire tree\n";
        cout << "9. Display the entire tree\n";
        cout << "0. Quit\n";
        choice = inputInteger("Option : ", 0, 9);
        cout << "\n";
        switch (choice) {
        case 1:
            nod = new node;
            int input;
            input = inputInteger("Enter an integer:");
            //cout << "Enter an integer : ";        
            nod->entry = input;
            //cin >> nod->entry;
            twee.insert(righ, nod);
            break;
        case 2:
            if (righ == NULL) {
                cout << "ERROR: BinaryTree is empty.\n";
                continue;
            }
            int num;
            num = inputInteger("Enter an integer:");
            /*cout << "Enter an integer : ";
            cin >> findThis;*/
            twee.remove(num);
            break;
        case 3:
            twee.Printcount();
            break;
        case 4:
            /*cout << "Enter an integer key to search:\n";
            cin >> findThis;*/
            int num1;
            num1 = inputInteger("Enter an integer:");
            twee.search(righ, num1);
            break;
        case 5:
            cout << "Pre-order Traversal of BinaryTree:\n";
            twee.preorder(righ);
            cout << "\n";
            break;
        case 6:
            cout << "In-order Traversal of BinaryTree:\n";
            twee.inorder(righ);
            cout << "\n";
            break;
        case 7:
            cout << "Post-order Traversal of BinaryTree:\n";
            twee.postorder(righ);
            cout << "\n";
            break;
        case 8:
            //MISSING DELETE TREE
           // twee.Delete(twee);
            break;
        case 9:
            cout << "Display BinaryTree:\n";
            twee.print(righ, twee.getCount());
            cout << "\n";
            break;
        case 0: return;
        default: cout << "\tERROR-Invalid Option. Please re-enter."; break;
        }
    } while (true);
}