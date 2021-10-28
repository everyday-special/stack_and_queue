/*
 */
#include "queue.h"

Queue::Queue()
{
	head = nullptr;
	tail = nullptr;
	size = new int(0);
}



Queue::~Queue()
{
	Node * curr = head;
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
{
	Party front(*(head->data));
	Node * temp = head;
	head = head->next;
	delete temp;
	temp = nullptr;
	head->prev = tail;
	tail->next = head;
	(*size)--;
	return front;
}

void Queue::peek()
{
	std::cout << *(head->data) << std::endl;
}

void Queue::display()
{
	recursiveDisplay(head);
}

void Queue::recursiveDisplay(Node * curr)
{
	std::cout << *(curr->data) << std::endl;
	if (curr != tail)
		recursiveDisplay(curr->next);
}
