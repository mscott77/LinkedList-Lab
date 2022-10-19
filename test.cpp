#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "LinkedList.h"


int main() {

	LinkedList<int> mylist;

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

}

