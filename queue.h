/* Purpose: Defines the menu class
 * Author: Matthew Lidell
 * Date: 10/31/2021
 * file: queue.h
 */
#pragma once
#include "party.h"
#include <iostream>

class Queue
/* Class representing restaurant waitlist/queue.
 * This class has a privately defined Node struct representing an item/node in the linked list
 * This class has 3 private data members:
 * 	- head - pointer to the the node at the front of the queue
 * 	- tail - pointer to the node at the end of the queue
 * 	- size - pointer to integer of the number of nodes in the list
 * This class has 7 public member functions:
 * 	-Default constructor
 *	-Default destructor
 *	-enqueue() - appends party/Node to the end of the queue
 *	-dequeue() - removes and returns party/Node at the front of the queue
 *	-peek() - prints party/Node at the front of the queue
 *	-display() - prints the size of the queue and all parties in the queue
 *	-getSize() - returns the size of the queue
 * This class has 1 private member fuctions:
 * 	-recursiveDisplay() - recursive backend for displaying all the items in the list
 */
{
	public:
		Queue();
		~Queue();
		void enqueue(Party& newParty);
		Party dequeue();
		void peek();
		void display();
		int getSize();

	private:
		struct Node
		/* Struct representing a node in the SongList singly linked list.
                 * Node has 2 data attributes:
                 *      - Song * data - pointer to the Song at this location in the list
                 *      - Node * next - pointer to the next Node in the list
		 *      - Node * prev - pointer to the previous Node in the list
                 * Node has 2 member functions:
                 *      - Constructor creating a new node where the data is the given song
                 *      - Default Destructor
                 */
		{
			Node(Party & newParty)
			/* Purpose: Instantiate a new Node. Sets data to newParty and next and prev to nullptr
                         * Parameters:
                         *      - newParty - Party to be stored in this node
                         * Return None
                         */
			{
				data = new Party(newParty);
				next = nullptr;
				prev = nullptr;
			}
			~Node()
			/* Purpose: Destroy allocated Node and associated data attributes.
                         * Parameters: None
                         * Return: None
                         */
			{
				delete data;
				data = nullptr;
				next = nullptr;
				prev = nullptr;
			}
			Party * data; // Used for storing party data at this node
			Node *next, *prev; // Used for storing link to next and previous nodes
		};
		Node *head, *tail; // Used for storing references to front and back of queue
		int * size; // Used for storing the queue size
		void recursiveDisplay(Node * curr, int idx);
};
