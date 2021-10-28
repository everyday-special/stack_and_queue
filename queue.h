#pragma once
#include "party.h"
#include <iostream>

class Queue
/*
 */
{
	public:
		Queue();
		~Queue();
		void enqueue(Party& newParty);
		Party dequeue();
		void peek();
		void display();

	private:
		struct Node
		{
			Node(Party & newParty)
			{
				data = new Party(newParty);
				next = nullptr;
				prev = nullptr;
			}
			~Node()
			{
				delete data;
				data = nullptr;
				next = nullptr;
				prev = nullptr;
			}
			Party * data;
			Node *next, *prev;
		};
		Node *head, *tail;
		int * size;
		void recursiveDisplay(Node * curr);
};
