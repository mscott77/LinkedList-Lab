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

	cout << "---------------------------test3--------------------------------------------" << endl;
	// test the insert tail function by itself - it was having problems inserting if there is no head already there...
	mylist.clear();
	//mylist.insertHead(0); this function should work without this line
	mylist.insertTail(1);
	mylist.insertTail(2);
	mylist.insertTail(3);
	mylist.insertTail(4);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;


	cout << "---------------------------test4--------------------------------------------" << endl;
	// test the remove() function if the given value is the first or last value
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	cout << "removing 1 from the list" << endl;
	mylist.remove(1); // FIXME: does not work, function cannot find the first item in the list
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	cout << "removing 4 from the list" << endl;
	mylist.remove(4); // works... but with side effects
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	// I am suspicious that after removing the final item in the list, the new final item will not be pointing to NULL anymore and there will
	// be no way to tell where the end of the list is...
	// call insertTail()again, which depends on knowing when it reaches NULL and see what happens...

	cout << "adding the number 5 to the TAIL of the list \n new list should be 1 2 3 5" << endl;
	mylist.insertTail(5);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;
	
	// ok well I guess it still works 
	// oh wait of course it works, in the remove function it assings the Node before the node you want to delete to whatever the Node you
	// want to delete's next value is. in this case it assigned the 2nd to last Node to point to what the last Node was pointing to, which was NULL

	cout << "---------------------------test5--------------------------------------------" << endl;
	
	// test the insertAfter() function
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	cout << "we will now insert the value 666 after the value 5..." << endl;
	mylist.insertAfter(666,5);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	cout << "we will now insert the value 666 after the value 666... but we will fail because it is a duplicate" << endl;
	mylist.insertAfter(666,666);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	cout << "we will now insert the value 31415 after the value 662607... but will fail because 662607 is not in the list" << endl;
	mylist.insertAfter(31415,662607);
	cout << endl << "Current List" << endl << mylist.toString() << endl << endl;

	cout << "double checking the size of the list for accuracy..." << endl;
	cout << mylist.size() << endl;




}

