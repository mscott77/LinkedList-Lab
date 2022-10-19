//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once

#include <string>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>{
public:

	// constructor
	LinkedList() {
		cout << endl << "In constructor" << endl;

		cout << "Leaving constructor" << endl;
	}
	// destructor
	~LinkedList() {
		cout << endl <<  "In destructor" << endl;

		cout << "Leaving destructor" << endl;
	}

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value){
		cout << endl <<  "In insertHead()" << endl;

		cout << "Leaving insertHead()" << endl;
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value){
		cout << endl <<  "In insertTail()" << endl;

		cout << "Leaving insertTail()" << endl;
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode){
		cout << endl <<  "In insertAfter()" << endl;

		cout << "Leaving insertAfter()" << endl;
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value){
		cout << endl <<  "In remove()" << endl;

		cout << "Leaving remove()" << endl;
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear(){
		cout << endl <<  "In clear()" << endl;

		cout << "Leaving clear()" << endl;
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index){
		cout << endl <<  "In at()" << endl;

		return 777;

		cout << "Leaving at()" << endl;
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size(){
		cout << endl <<  "In size()" << endl;

		return 777;

		cout << "Leaving size()" << endl;
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString(){
		cout << endl <<  "In toString()" << endl;

		return "XXXX";

		cout << "Leaving toString()" << endl ;
	}

};
