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
    while (1) {
        cout << "\n";
        cout << "1. Insert a node/leaf\n";
        cout << "2. Delete a node/leaf\n";
        //cout << "3. Count of nodes/leaves\n";
        cout << "4. Search a node/leaf\n";
        cout << "5. Pre-order traversal\n";
        cout << "6. In-order traversa\n";
        cout << "7. Post-order Traversal\n";
        //cout << "8. Delete the entire tree\n";
        cout << "9. Display the entire tree\n";
        cout << "0. Quit\n";
        cout << "Option : ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
        case 1:
            nod = new node;
            cout << "Enter an integer : ";
            cin >> nod->entry;
            twee.insert(righ, nod);
            break;
        case 2:
            if (righ == NULL) {
                cout << "ERROR: BinaryTree is empty.\n";
                continue;
            }
            cout << "Enter an integer : ";
            cin >> findThis;
            twee.remove(findThis);
            break;
        case 3:
            //MISSING COUNT
            break;
        case 4:
            cout << "Enter an integer key to search:\n";
            cin >> findThis;
            twee.search(righ, findThis);
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
            break;
        case 9:
            cout << "Display BinaryTree:\n";
            twee.print(righ, 1);
            cout << "\n";
            break;
        case 0: exit(0);
        default: cout << "\tERROR-Invalid Option. Please re-enter."; break;
        }
    }
}