#pragma once
#include "contacts.h"
#include <iostream>

class Stack
/*
 */
{
	public:
		Stack();
		~Stack();
		void push(ContactInfo& newContact);
		ContactInfo pop();
		void peek();
		void display();
		int getSize();
	
	private:
		void grow();
		int * max;
		int * size;
		ContactInfo * contacts;
		//Save to file
		//Load from file ?
};
