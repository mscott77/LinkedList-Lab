#pragma once

#include <string>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>{
private:
	struct Node {
		T data; // the data to store in this node 
		Node* next; // a pointer of type Node that points to the next node
		// constructor 
		// 	-takes a derefenced pointer for the first value, and pointer of type Node for the next value.
		//	-if no next_val is specified, it automatically sets that pointer to NULL
		Node(const T& the_data, Node* next_val = NULL){
			next = next_val;
			data = the_data;
		}
	};
	Node *head; // create the head pointer, which will point to NULL on creation, and eventually will point to the head of the list
	int numItems; // a counter to keep track of the number of items in the list
public:

	//--------------------------------------constructor-----------------------------------------------------(done)
	LinkedList() {
		cout << endl << "In constructor" << endl;

		head = NULL; // since there are no Nodes created yet for head to point to, set it to NULL so that we know the list is empty
		numItems = 0; // initialize the number of items in our list to be 0

		cout << "Leaving constructor" << endl;
	}
	//-----------------------------------------------------destructor-----------------------------------------------------(done)
	~LinkedList() {
		cout << endl <<  "In destructor" << endl;

		// clear the entire list
		while(head != NULL){ // keep going until the head is pointing at NULL ie. until there are no items left in the list
			Node *current = head; // make a pointer named current that points to the same thing head points to
			head = head->next; // make head point to head's next value, which will be the next value in the list, or NULL if head is the last value in the list
			delete current; // delete the item that current is pointing to
		}

		cout << "Leaving destructor" << endl;
	}

	/*
	-----------------------------------------------------insertHead-----------------------------------------------------(done)

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value){
		cout << endl <<  "In insertHead()" << endl;

		// check to make sure it's not a duplicate
		bool isDuplicate = false;
		for(Node *ptr = head; ptr != NULL; ptr=ptr->next)
		{
			if ((ptr->data) == value)
			{
				isDuplicate = true;
			}
		}

		// if it's a duplicate, don't insert it
		if (isDuplicate == true) 
		{
			cout << "value given to insert was a duplicate and was NOT inserted" << endl;
		}
		else // if it's not a duplicate, insert it
		{
			Node *newNode = new Node(value);
			newNode->next = head;
			head = newNode;

			numItems ++;
		}

		cout << "Leaving insertHead()" << endl;
	}

	/*
	-----------------------------------------------------insertTail-----------------------------------------------------(done)

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value){							
		cout << endl <<  "In insertTail()" << endl;

		// check to see if it's a duplicate
		bool isDuplicate = false;
		for(Node *ptr = head; ptr != NULL; ptr=ptr->next)
		{
			if ((ptr->data) == value)
			{
				isDuplicate = true;
			}
		}
		if (isDuplicate) { 
			cout << "value given to insert was a duplicate and was NOT inserted" << endl;
		}
		else{
			// if it's not a duplicate, add it to the list
			// this function has problems if there's not already an item in the list,
			// so if the list is empty and insertTail() is called, just call insertHead() instead
			if(numItems == 0)
			{
				insertHead(value);	
			}
			else{
				for(Node *ptr = head; ptr != NULL; ptr=ptr->next)
				{
					if ((ptr->next) == NULL){ // if it's the last item in the list
						Node *newNode = new Node(value);
						ptr->next = newNode;
						break; // break so it only does this one time and doesn't make an infinite loop
						// newNode's value should be automatically set to NULL in the Node constructor
					}

				}
				numItems ++;
			}
		}


		cout << "Leaving insertTail()" << endl;
	}

	/*
	-----------------------------------------------------insertAfter-----------------------------------------------------(done)

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode){
		cout << endl <<  "In insertAfter()" << endl;

		bool wasFound = false;
		bool wasDuplicate = false;

		// first, make sure the value to insert is not a duplicate, if it is, you can skip all the other looping
		for(Node *ptr = head; ptr != NULL; ptr=ptr->next) // loop through the entire list
		{
			if (ptr->data == value){
				wasDuplicate = true;
				cout << "the item you gave to insert was a duplicate item. nothing was added to the list" << endl;
			}
		}

		if (!wasDuplicate){
			for(Node *ptr = head; ptr != NULL; ptr=ptr->next) // loop through the entire list
			{
				if ((ptr->data) == insertionNode) // insert once you have found a value matching insertionNode
				{

					Node *newNode = new Node(value,ptr->next); // create a new Node, assign it the given value, and make sure to assign it's next to be the same next as the Node you're putting it after
					ptr->next = newNode;
					numItems++;
					wasFound = true;
					cout << "the value " << value << " has been inserted after the value " << insertionNode << endl;
					break;
				}
			}
			if (!wasFound){ // the value to insert was not a duplicate, but the value to insert after was not found 
				cout << "there was no item in the list matching the given value: " << insertionNode << ", so nothing was added to the list" << endl;
			}
		}

		cout << "Leaving insertAfter()" << endl;
	}

	/*
	-----------------------------------------------------remove-----------------------------------------------------(done)
	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value){
		cout << endl <<  "In remove()" << endl;

		bool wasFound = false;

		// first check for the case where the item in question happens to be the first item in the list
		if (head != NULL){
			if ((head->data) == value)
			{
				Node *oldNode = head;
				head = head->next;
				delete oldNode;
				cout << "Node has been deleted. Deleted Item was the first item in the list" << endl;

				numItems --; // decrement the number of items counter 
				wasFound = true;
			}
			else // if the first one is not a match, go through the rest of them 
			{
				int i = 0;
				for(Node *ptr = head; ptr != NULL; ptr=ptr->next)
				{	
					cout << "on loop #" << i << endl;
					if ((ptr->next) != NULL) // do this for every value except the last value, because the last value doesn't have a pt->next->data because its NULL
					{
						if ((ptr->next->data) == value) // if the NEXT value is the one you want to remove
						{
							cout << "found a match at index " << i + 1 << endl;
							Node *temp = ptr->next; // make a temporary placeholder on the one you want to delete so you don't lose it 
							ptr->next = ptr->next->next; // assign the current nodes 'next' to point to the node AFTER the one you want to delete
							delete temp; // now delete the one you want to delete

							cout << "Node has been deleted" << endl;
							numItems --; // decrement the number of items counter 
							wasFound = true;
							break; // break, so that you don't get a segmentation fault later, also because there will be no duplicate numbers in the list anyways
						}
					}
					i++;
				}
			}
		}
		if (!wasFound){
			cout << " NO MATCH was found, NO list items were deleted" << endl;
		}
		cout << "Leaving remove()" << endl;
	}

	/*
	-----------------------------------------------------clear-----------------------------------------------------(done)
	Remove all nodes from the list.
	*/
	void clear(){
		cout << endl <<  "In clear()" << endl;

		// clear the entire list
		while(head != NULL){ // keep going until the head is pointing at NULL ie. until there are no items left in the list
			Node *current = head; // make a pointer named current that points to the same thing head points to
			head = head->next; // make head point to head's next value, which will be the next value in the list, or NULL if head is the last value in the list
			delete current; // delete the item that current is pointing to
		}
		numItems = 0;

		cout << "Leaving clear()" << endl;
	}

	/*
	-----------------------------------------------------at-----------------------------------------------------(done)

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index){
		cout << endl <<  "In at()" << endl;

		// confirm whether the given index is in range or not
		if((index < 0) || (index >= numItems))
		{
			throw out_of_range("ERROR index was not in range of the current list");
		}

		// after confirming index is valid, iterate through the list till you get to that index
		int currentIndex = 0;
		for(Node *ptr = head; ptr != NULL; ptr=ptr->next)
		{
			if (currentIndex == index)
			{
				return ptr->data;
			}
			currentIndex ++;
		}
	}

	/*
	-----------------------------------------------------size-----------------------------------------------------(done)

	Returns the number of nodes in the list.
	*/
	int size(){
		cout << endl <<  "In size()" << endl;
		cout << "Leaving size()" << endl;
		return numItems;
	}

	/*
	-----------------------------------------------------toString-----------------------------------------------------(done)
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString(){
		// initialize a stringream
		stringstream ss;
		// loop through the LinkedList 
		for(Node *ptr = head; ptr != NULL; ptr=ptr->next)
		{
				ss << ptr->data; // add current value to stringstream (don't forget to convert it to a string)
				if ((ptr->next) != NULL){ ss << " ";} // don't add a space on the last item
		}
		return ss.str();
	}




};
