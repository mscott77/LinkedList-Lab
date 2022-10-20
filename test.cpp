#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "LinkedList.h"


int main() {

	LinkedList<int> mylist;

	mylist.insertHead(1);
	mylist.insertHead(2);
	mylist.insertHead(3);
	mylist.insertHead(666);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	// test the size() function
	cout << "the size of the list is: " << mylist.size() << endl;

	// test the at() function
	int tempVal;
	tempVal = mylist.at(2);
	cout << "list and index 2 is: " << to_string(tempVal) << endl;
	tempVal = mylist.at(3);
	cout << "list at index 3 is: " << to_string(tempVal) << endl;

	// test the clear function
	cout << "now we will clear the list..." << endl;
	mylist.clear();
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;
	cout << "the size of the list is: " << mylist.size() << endl;

	// make some new stuff
	mylist.insertHead(4);
	mylist.insertHead(3);
	mylist.insertHead(2);
	mylist.insertHead(1);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	// test the at() function again
	tempVal;
	tempVal = mylist.at(3);
	cout << "list and index 3 is: " << to_string(tempVal) << endl;
	/* // uncomment the next two lines if you want to test the out of range feature of the at function
	tempVal = mylist.at(4);
	cout << "list at index 4 is: " << to_string(tempVal) << endl;
	*/


	/*
	mylist.toString();

	mylist.insertHead(5);
	mylist.insertHead(6);
	mylist.insertHead(7);
	mylist.insertHead(8);
	mylist.toString();

	mylist.insertTail(4);
	mylist.insertTail(3);
	mylist.insertTail(2);
	mylist.toString();

	mylist.insertAfter(666,1);
	mylist.toString();

	mylist.remove(5);
	mylist.toString();

	mylist.at(2);
	mylist.size();

	mylist.clear();
	mylist.toString();
	*/

}

