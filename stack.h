/* Purpose: Defines the menu class
 * Author: Matthew Lidell
 * CS260 Project 2
 * Date: 10/31/2021
 * file: stack.h
 */
#pragma once
#include "contacts.h"
#include "utils.h"
#include <iostream>
#include <fstream>

const char FILENAME[] = "stack.txt"; // name of the file for saving/loading stack data

class Stack
/* Class representing a stack of contact information for promotional purposes
 * This class has 3 private data memebers:
 * 	-contacts - pointer to dynamically allocated array for ContactInfo objects
 * 	-max - pointer to int containing maximum size of currently allocated array
 * 	-size - pointer to int containing current size of allocated array
 * This class has 9 public member functions:
 * 	-Constructor
 * 	-Destructor
 * 	-push() - adds data to the top of the stack
 * 	-pop() - removes data from the top of the stack and returns it
 * 	-peek() - displays the data at the top of the stack without removing it
 * 	-display() - displays all of the data in the stack from top to bottom
 * 	-getSize() - returns the current size of the array
 * 	-saveToFile - saves data in the stack to "stack.txt"
 * 	-loadFromFile - loads data into the stack from "stack.txt"
 * This class has 1 private member function:
 *	-grow() - allocates a new, larger array for contacts and deletes the old one
 */
{
	public:
		Stack(int max);
		~Stack();
		void push(ContactInfo& newContact);
		ContactInfo pop();
		void peek();
		void display();
		int getSize();
                bool saveToFile(const char fileName[]);
                bool loadFromFile(const char fileName[]);
	
	private:
		void grow();
		int * max; // maximum size of the currently allocated array
		int * size; // current size of array
		ContactInfo * contacts; // pointer to the dynamically allocated array
};
