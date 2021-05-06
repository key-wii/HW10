#pragma once
// Name: Prof Q
// Date: 4-26-21
// Description: Binary tree node

#include <iostream>
using namespace std;

template <class T>
class Binary_Tree_Node
{
private:
	T data_field;
	Binary_Tree_Node* left_field;
	Binary_Tree_Node* right_field;

public:
	//constructor
	Binary_Tree_Node(const T& initData = T(), Binary_Tree_Node* initLeft = nullptr, Binary_Tree_Node* initRight = nullptr)
	{
		data_field = initData;
		left_field = initLeft;
		right_field = initRight;
	}

	// Accessor
	T& data()
	{
		return data_field;
	}

	Binary_Tree_Node*& left()
	{
		return left_field;
	}

	Binary_Tree_Node*& right()
	{
		return right_field;
	}

	const Binary_Tree_Node* left() const
	{
		return left_field;
	}

	const Binary_Tree_Node* right() const
	{
		return right_field;
	}

	void setData(const T& newData)
	{
		data_field = newData;
	}

	const T& data() const
	{
		return data_field;
	}

	void  setLeft(Binary_Tree_Node* newLeft)
	{
		left_field = newLeft;
	}

	void  setRight(Binary_Tree_Node* newRight)
	{
		right_field = newRight;
	}

	bool isLeaf() const
	{
		return (left_field == nullptr && right_field == nullptr);
	}

};

template<class T>
void print_tree(const string& prefix, const Binary_Tree_Node<T>* node, bool isLeft, bool root, bool last)
{
	if (node != NULL)
	{
		cout << prefix;
		if (!root)
		{
			if (isLeft)
			{
				if (node->left() == NULL && node->right() == NULL)
					cout << char(192) << string(3, char(196));
				else
					cout << char(195) << string(3, char(196));
			}
			else
			{
				if (last)
					cout << char(192) << string(3, char(196));
				else
					cout << char(195) << string(3, char(196));
			}
			cout << " " << node->data() << '\n';
		}
		else
			cout << "    " << node->data() << '\n';


		// enter the next tree level - left and right branch
		string s = "    ";
		s[0] = char(179);
		print_tree(prefix + (isLeft ? s : "    "), node->left(), true, false, false);
		print_tree(prefix + (isLeft ? s : "    "), node->right(), false, false, true);
	}
}

template<class T>
void delete_tree(Binary_Tree_Node<T>* leaf) // Recursive
{
	if (leaf == NULL)
		return;

	/* first delete both subtrees */
	delete_tree(leaf->left());
	delete_tree(leaf->right());

	/* then delete the node */
	cout << "\n\t\tDeleting: " << leaf->data();
	delete leaf;

}
template<class T>
void deleteTree(Binary_Tree_Node<T>* leaf) // Recursive
{
	if (leaf == nullptr)
		return;

	/* first delete both subtrees */
	deleteTree(leaf->left());
	deleteTree(leaf->right());

	/* then delete the node */
	//cout << "\n\t\tDeleting: " << leaf->data();
	delete leaf;

}
void option1()
{
	// Bonsai Tree of string

	cout << "\n\tGrowing of my Bonsai binary tree (strings)\n";
	Binary_Tree_Node<string>* root = nullptr;

	root = new Binary_Tree_Node<string>;

	root->setData("root");
	cout << "\n\tA> root sprouts with no branch.\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << "\n";
	system("pause");

	Binary_Tree_Node<string>* branch1 = new Binary_Tree_Node<string>;
	branch1->setData("branch #1");
	Binary_Tree_Node<string>* branch2 = new Binary_Tree_Node<string>;
	branch2->setData("branch #2");

	root->setLeft(branch1);
	root->setRight(branch2);
	cout << "\n\tB> " << root->data() << " grows two branches: " << branch1->data() << " and " << branch2->data() << ".\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << "\n";
	system("pause");

	Binary_Tree_Node<string>* leftLeaf1 = new Binary_Tree_Node<string>;
	leftLeaf1->setData("leaf #1");
	root->left()->setLeft(leftLeaf1);
	Binary_Tree_Node<string>* leftLeaf2 = new Binary_Tree_Node<string>;
	leftLeaf2->setData("leaf #2");
	root->left()->setRight(leftLeaf2);

	cout << "\n\tC> " << root->left()->data() << " grows two leaves: " << leftLeaf1->data() << " and " << leftLeaf2->data() << ".\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	system("pause");

	Binary_Tree_Node<string>* rightLeaf1 = new Binary_Tree_Node<string>;
	rightLeaf1->setData("leaf #3");
	root->right()->setLeft(rightLeaf1);
	Binary_Tree_Node<string>* rightLeaf2 = new Binary_Tree_Node<string>;
	rightLeaf2->setData("leaf #4");
	root->right()->setRight(rightLeaf2);
	cout << "\n\tD> " << root->right()->data() << " grows two leaves: " << rightLeaf1->data() << " and " << rightLeaf2->data() << ".\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	system("pause");

	Binary_Tree_Node<string>* fruit = new Binary_Tree_Node<string>;
	fruit->setData("apple");
	leftLeaf1->setLeft(fruit);
	cout << "\n\tE> " << root->left()->left()->data() << " sprouts and yields a fruit (" << fruit->data() << ").\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	system("pause");

	Binary_Tree_Node<string>* fruit2 = new Binary_Tree_Node<string>;
	fruit2->setData("orange");
	Binary_Tree_Node<string>* fruit3 = new Binary_Tree_Node<string>;
	fruit3->setData("coconut");
	rightLeaf1->setLeft(fruit2);
	rightLeaf1->setRight(fruit3);
	cout << "\n\tF> " << root->right()->left()->data() << " sprouts and yields two fruits (" << fruit2->data() << " and " << fruit3->data() << ").\n\n";
	print_tree("\t\t", root, false, true, false);
	cout << '\n';
	system("pause");

	cout << "\n\tG> Delete tree (recursive).\n";
	delete_tree<string>(root);
	cout << '\n';
	root = NULL;
	if (root != NULL)
	{
		cout << '\n';
		print_tree("\t\t", root, false, true, false);
	}
	return;
}
