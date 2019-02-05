// Cory Mollenhour
// CSCI 3110 - 001
// Project #6
// Due : 04/06/2018
//Tree Program - This program will create a binary search tree
//to find a specified word and then delete the tree on completion.

//Includes
#include "WordTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Custom Tree constructor initializes the root node of the tree
WordTree::WordTree(Node * node) {
	root = node;
	root->count = 1;
	root->left = nullptr;
	root->right = nullptr;
}

//Destructor deletes the tree starting with the leaf nodes
//and back-tracking up to the root in post-order
WordTree::~WordTree() {
	deleteNodes(root);
}

//Recursive function to delete nodes in post-order (Left-Right-Delete)
void WordTree::deleteNodes(Node * node) {
	if (node->left) {
		deleteNodes(node->left);
	}
	if (node->right) {
		deleteNodes(node->right);
	}
	delete node;
	node = nullptr;
}

//Insert function takes a specified node pointer recursively compares
//node data to the given word before inserting a new word in the tree.
void WordTree::insert(Node * node, string word) {
	if (node->data == "") {
		node->data = word;
	}else {
		if (node->data == word) {
			node->count++;
		}
		else if (word < node->data) {
			if (!node->left) {
				node->left = new Node;
			}
			insert(node->left, word);
		}
		else if (word > node->data) {
			if (!node->right) {
				node->right = new Node;
			}
			insert(node->right, word);
		}
	}
}

//This function will recursively print the tree using "In-Order" traversal
void WordTree::printInOrder(Node * node, int threshold, int &totalCount) {
	if (node->left) {
		printInOrder(node->left, threshold, totalCount);
	}
	if (node->count >= threshold) {
		cout << node->data << "(" << node->count << ")" << endl;
		totalCount++;
	}
	if (node->right) {
		printInOrder(node->right, threshold, totalCount);
	}
}

//Publicly accessed function to find a specified word and show the word count
void WordTree::findNode(Node * node, string word) {
	int searchCount = 0;
	cout << "Searching for occurrences of the word '" << word << "'" << endl;
	queryNodes(node, word, searchCount);
	if(searchCount > 0)
		cout << "The word '" << word << "' occurs " << searchCount << " time(s) in the text." << endl << endl;
	else
		cout << "The word '" << word << "' was not found in the text." << endl << endl;
}

//Privately accessed function to find a specified word recursively and pass the
// number of occurences by reference
void WordTree::queryNodes(Node * node, string word, int &searchCount) {
	if (node->data == word) {
		searchCount = node->count;
	}
	else if (word < node->data) {
		if (node->left) {
			queryNodes(node->left, word, searchCount);
		}
	}
	else if (word > node->data) {
		if (node->right) {
			queryNodes(node->right, word, searchCount);
		}
	}
}
