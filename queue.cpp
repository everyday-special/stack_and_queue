/* Purpose: Defines the menu class
 * Author: Matthew Lidell
 * Date: 10/31/2021
 * file: queue.cpp
 */
#include "queue.h"

Queue::Queue()
/* Purpose: Default constructor for queue object
 * Parameters: None
 * Return: None
 */
{
	head = nullptr;
	tail = nullptr;
	size = new int(0);
}



Queue::~Queue()
/* Purpose: Default destructor for queue object
 * Parameters: None
 * Return: None
 */
{
	Node * curr = head;
	if (tail)
		tail->next = nullptr;
	while(curr)
	{
		head = head->next;
		delete curr;
		curr = head;
	}
	delete size;
	size = nullptr;
	tail = nullptr;
}



void Queue::enqueue(Party& newParty)
/* Purpose: adds a new party/node to the queue
 * Parameters: newParty - party to be added to the queue
 * Return: None
 */
{
	Node * newNode = new Node(newParty);
	if (!head)
	{
		head = newNode;
		tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->next = head;
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		head->prev = tail;

	}
	(*size)++;
}



Party Queue::dequeue()
/* Purpose: removes and returns the party at the front of the queue or an empty party object if the queue is empty (empty partys can be check by using Party::isEmpty())
 * Parameters: None
 * Returns: Party - party at the front of the queue or empty party is queue is empty
 */
{
	if ((*size) == 0)
	{
		Party party = Party(); // Empty party to be returned in the case of empty queue
		return party;
	}
	else
	{
		Party front(*(head->data)); // Store party at the front of the list
		Node * temp = head;
		if ((*size) == 1)
		{
			head = nullptr;
			tail = nullptr;
			delete temp;
			temp = nullptr;
		}
		else
		{
			head = head->next;
			delete temp;
			temp = nullptr;
			head->prev = tail;
			tail->next = head;
		}
		(*size)--;
		return front;
	}
}



void Queue::peek()
/* Purpose: Prints the party data at the front of the queue or "Queue is empty" if the queue is empty
 * Parameters: None
 * Return: None
 */
{
	if ((*size) > 0)
		std::cout << *(head->data) << std::endl;
	else
		std::cout << "Queue is empty." << std::endl;
}



void Queue::display()
/* Purpose: Prints the data of all parties in the list or "Queue is empty" if the queue is empty
 * Parameters: None
 * Return: None
 */
{
	if ((*size) > 0)
		recursiveDisplay(head, 0);
	else
		std::cout << "Queue is empty." << std::endl;
}



void Queue::recursiveDisplay(Node * curr, int idx)
/* Purpose: Recursive backend for displaying the entire queue
 * Parameters:
 * 	- Node * curr - pointer to the current node in the queue
 * 	- int idx - index of the current node in the queue
 * Return: None
 */
{
	std::cout << "Index: " << idx << std::endl;
	std::cout << *(curr->data) << std::endl;
	if (curr != tail)
		recursiveDisplay(curr->next, ++idx);
}



int Queue::getSize()
/* Purpose: returns the current size of the queue
 * Parameters: None
 * Return: int - current size of the queue
 */
{
	return *size;
}
