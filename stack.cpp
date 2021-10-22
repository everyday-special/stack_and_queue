#include "stack.h"

Stack::Stack()
{
	max = new int(4);
	size = new int(0);
	contacts = new ContactInfo[*max];
}

Stack::~Stack()
{
	delete max;
	max = nullptr;
	delete size;
	size = nullptr;
	delete [] contacts;
	contacts = nullptr;
}

void Stack::grow()
{
	*max = 2 * *max;
	ContactInfo * temp = new ContactInfo[*max];
	for (int i = 0; i < *size; i++)
		temp[i] = contacts[i];
	delete [] contacts;
	contacts = temp;
}

void Stack::peek()
{
	std::cout << contacts[*size - 1] << std::endl;
}

void Stack::display()
{
	std::cout << "Top of the stack:\n" << std::endl;
	for (int i = *size - 1; i >= 0; i--)
		std::cout << contacts[i] << '\n' << std::endl;
}

void Stack::push(ContactInfo& newContact)
{
	contacts[(*size)++] = newContact;
	if (*size == *max)
		grow();
}
