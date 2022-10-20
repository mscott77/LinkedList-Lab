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

	// make some new stuff and test teh insertHeads' anti-duplicate ability
	mylist.insertHead(4);
	mylist.insertHead(3);
	mylist.insertHead(2);
	mylist.insertHead(1);
	mylist.insertHead(1);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	// test the at() function again
	tempVal;
	tempVal = mylist.at(3);
	cout << "list and index 3 is: " << to_string(tempVal) << endl;
	/* // uncomment the next two lines if you want to test the out of range feature of the at function (it will break the program)
	tempVal = mylist.at(4);
	cout << "list at index 4 is: " << to_string(tempVal) << endl;
	*/

	// test the insertTail() function and it's anti-duplicate ability
	mylist.insertTail(5);
	mylist.insertTail(6);
	mylist.insertTail(7);
	mylist.insertTail(8);
	mylist.insertTail(8);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	// test the remove() function
	cout << "removing the number 6 from the list" << endl;
	mylist.remove(6);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;
	cout << "size of list is: " << mylist.size() << endl;

	// test the remove() function if the given value is not in the list

	cout << "removing the number 666 from the list" << endl;
	mylist.remove(666);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;
	cout << "size of list is: " << mylist.size() << endl;
	

}

