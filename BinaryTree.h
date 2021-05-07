// Participants: Christopher
// Date: 5-6-21
// Description: BinaryTree
#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int entry;
    struct node *left;
    struct node *righ;
}*righ;
class BinaryTree {
    public:
        void insert(node*, node*);
        void remove(int);
        void find(int, node**, node**);
        void noNull(node*, node*);
        void oneNull(node*, node*);
        void bothNull(node*, node*);
        void Printcount();
        void search(node*, int);
        void preorder(node*);
        void inorder(node*);
        void postorder(node*);
        //void delete();
        void print(node*, int);
        int getCount();
        BinaryTree() {
            righ = NULL;
            count = 0;
        }
private:
    int count;
};

int BinaryTree::getCount()
{
    return count;
}
void BinaryTree::Printcount()
{
    cout << "\n\tCount of Nodes = " << count << ".\n";
}

void BinaryTree::insert(node *tree, node *newnode) {
    if (righ == NULL) {
        righ = new node;
        righ->entry = newnode->entry;
        righ->left = NULL;
        righ->righ = NULL;
        count++;
        return;
    }
    if (tree->entry > newnode->entry) {
        if (tree->left != NULL) {
            insert(tree->left, newnode);
        }
        else {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->righ = NULL;
            count++;
            return;
        }
    }
    else {
        if (tree->righ != NULL) {
            insert(tree->righ, newnode);
        }
        else {
            tree->righ = newnode;
            (tree->righ)->left = NULL;
            (tree->righ)->righ = NULL;
            count++;
            return;
        }
    }
}
void BinaryTree::remove(int i) {
    node*a, *b;
    if (righ == NULL) {
        cout << "ERROR: BinaryTree is empty.\n";
        return;
    }
    find(i, &a, &b);
    if (b == NULL) {
        cout << "ERROR: Not in BinaryTree.\n";
        return;
    }
    if (b->left != NULL && b->righ != NULL) noNull(a, b);
    if ((b->left != NULL && b->righ == NULL) || (b->left == NULL && b->righ != NULL)) oneNull(a, b);
    if (b->left == NULL && b->righ == NULL) bothNull(a, b);
    free(b);
    count--;
}
void BinaryTree::find(int i, node **a, node **b) {
    node *ptr, *ptrTemp;
    if (righ == NULL) {
        *b = NULL;
        *a = NULL;
        return;
    }
    if (i == righ->entry) {
        *b = righ;
        *a = NULL;
        return;
    }
    if (i < righ->entry)
        ptr = righ->left;
    else
        ptr = righ->righ;
    ptrTemp = righ;
    while (ptr != NULL) {
        if (i == ptr->entry) {
            *b = ptr;
            *a = ptrTemp;
            return;
        }
        ptrTemp = ptr;
        if (i < ptr->entry)
            ptr = ptr->left;
        else
            ptr = ptr->righ;
    }
    *b = NULL;
    *a = ptrTemp;
}
void BinaryTree::noNull(node *a, node *b) {
    node *ptr, *ptrTemp, *suc, *parsuc;
    ptrTemp = b;
    ptr = b->righ;
    while (ptr->left != NULL) {
        ptrTemp = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrTemp;
    if (suc->left == NULL && suc->righ == NULL)
        bothNull(parsuc, suc);
    else
        oneNull(parsuc, suc);
    if (a == NULL) {
        righ = suc;
    }
    else {
        if (b == a->left)
            a->left = suc;
        else
            a->righ = suc;
    }
    suc->left = b->left;
    suc->righ = b->righ;
    cout << "Removal successful\n";
}
void BinaryTree::oneNull(node *a, node *b) {
    node *child;
    if (b->left != NULL)
        child = b->left;
    else
        child = b->righ;
    if (a == NULL) {
        righ = child;
    }
    else {
        if (b == a->left)
            a->left = child;
        else
            a->righ = child;
    }
    cout << "Removal successful\n";
}
void BinaryTree::bothNull(node *a, node *b) {
    if (a == NULL) {
        righ = NULL;
    }
    else {
        if (b == a->left)
            a->left = NULL;
        else
            a->righ = NULL;
    }
    cout << "Removal successful\n";
}
void BinaryTree::search(node *root, int getThis) {
    int depth = 0;
    node *temp = new node;
    temp = root;
    while (temp != NULL) {
        depth++;
        if (temp->entry == getThis) {
            cout << "Found\n";
            return;
        }
        else if (temp->entry > getThis)
            temp = temp->left;
        else
            temp = temp->righ;
    }
    cout << "Not found\n";
    return;
}
void BinaryTree::preorder(node *ptr) {
    if (righ == NULL) {
        cout << "Tree is empty\n";
        return;
    }
    if (ptr != NULL) {
        cout << ptr->entry << " ";
        preorder(ptr->left);
        preorder(ptr->righ);
    }
}
void BinaryTree::inorder(node *ptr) {
    if (righ == NULL) {
        cout << "Tree is empty\n";
        return;
    }
    if (ptr != NULL) {
        inorder(ptr->left);
        cout << ptr->entry << " ";
        inorder(ptr->righ);
    }
}
void BinaryTree::postorder(node *ptr) {
    if (righ == NULL) {
        cout << "Tree is empty\n";
        return;
    }
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->righ);
        cout << ptr->entry << " ";
    }
}
void BinaryTree::print(node *ptr, int level) {
    int i;
    if (ptr != NULL) {
        cout <<"\n\t";
        for (i = 0; i < level; i++)
            cout << " ";
        cout << ptr->entry;
        print(ptr->left, level);
        print(ptr->righ, level);
    }
}