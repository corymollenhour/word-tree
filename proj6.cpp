// Cory Mollenhour
// CSCI 3110 - 001
// Project #6
// Due : 04/06/2018
//Tree Program - This program will create a binary search tree
//to find a specified word and then delete the tree on completion.

//Main Program Driver

//Includes
#include "wordtree.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

//User Defined constants
#define THRESHOLD 4
#define FINDWORD1 "word"
#define FINDWORD2 "stack"

using namespace std;

//Driver
int main() {
	ifstream inFile;
	Node * node = new Node;
	WordTree tree(node);
	string newWord;
	int count = 0;

	if (!inFile.is_open()) {
		inFile.open("input.txt");
		while (!inFile.eof()) {
			getline(inFile, newWord, ' ');
			std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);
			if(newWord != "")
				tree.insert(node, newWord);
		}
	}
	cout << "Word tree built and loaded" << endl << endl;
	cout << "Finding all words with "<< THRESHOLD << " or more occurrences:" << endl;
	tree.printInOrder(node, THRESHOLD, count);
	cout << count << " nodes had words with " << THRESHOLD << " or more occurence(s)." << endl << endl;
	
	tree.findNode(node, FINDWORD1); //First word search
	tree.findNode(node, FINDWORD2); //Second word search

	system("pause");
	return 0;
}
