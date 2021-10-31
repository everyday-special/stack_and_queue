#pragma once
#include "contacts.h"
#include "utils.h"
#include <iostream>
#include <fstream>

const char FILENAME[] = "stack.txt";

class Stack
/*
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
		int * max;
		int * size;
		ContactInfo * contacts;
};
