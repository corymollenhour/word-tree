// Cory Mollenhour
// CSCI 3110 - 001
// Project #6
// Due : 04/06/2018
//Tree Program - This program will create a binary search tree
//to find a specified word and then delete the tree on completion.

#ifndef WORDTREE_H
#define WORDTREE_H
#include <fstream> 
using namespace std;

struct Node {
	string data;
	int count = 1;
	Node * left = NULL;
	Node * right = NULL;
};

class WordTree {
	void queryNodes(Node * node, string word, int &searchCount);	// Recursive function to search for word
	Node * root;													// This is the top most node of the tree
public:
	void insert(Node * node, string word);							// Recursive function to insert a word
	WordTree::WordTree(Node * node);								// Custom constructor
	WordTree::~WordTree();											// Destructor to delete tree
	void findNode(Node * node, string word);						// Publicly accessed search function
	void printInOrder(Node * node, int threshold, int &totalCount);	// Prints the whole tree of words that meet threshold
	void deleteNodes(Node * node);									// Recursively delete nodes of the tree
};


#endif
