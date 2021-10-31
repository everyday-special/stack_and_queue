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
	if ((*size) == 0)
	{
		Party party = Party();
		return party;
	}
	else
	{
		Party front(*(head->data));
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
{
	if ((*size) > 0)
		std::cout << *(head->data) << std::endl;
	else
		std::cout << "Queue is empty." << std::endl;
}

void Queue::display()
{
	if ((*size) > 0)
		recursiveDisplay(head, 0);
	else
		std::cout << "Queue is empty." << std::endl;
}

void Queue::recursiveDisplay(Node * curr, int idx)
{
	std::cout << "Index: " << idx << std::endl;
	std::cout << *(curr->data) << std::endl;
	if (curr != tail)
		recursiveDisplay(curr->next, ++idx);
}


int Queue::getSize()
{
	return *size;
}
