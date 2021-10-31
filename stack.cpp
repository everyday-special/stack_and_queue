#include "stack.h"

Stack::Stack(int max)
{
	this->max = new int(max);
	size = new int(0);
	contacts = new ContactInfo[*(this->max)];
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
	if ((*size) > 0)
		std::cout << contacts[*size - 1] << std::endl;
	else
		std::cout << "Stack is empty." << std::endl;
}

void Stack::display()
{
	if ((*size) > 0)
	{
		std::cout << "Top of the stack:\n" << std::endl;
		for (int i = *size - 1; i >= 0; i--)
			std::cout << contacts[i] << '\n' << std::endl;
	}
	else
		std::cout << "Stack is empty." << std::endl;
}

void Stack::push(ContactInfo& newContact)
{
	contacts[(*size)++] = newContact;
	if (*size == *max)
		grow();
}


ContactInfo Stack::pop()
{
	if ((*size) > 0)
		return contacts[--(*size)];
	else
	{
		ContactInfo contact = ContactInfo();
		return contact;
	}
}


int Stack::getSize()
{
	return *size;
}


bool Stack::saveToFile(const char fileName[])
{
	std::ofstream outFile;
	char tempName[MAX_SIZE];
	char tempEmail[MAX_SIZE];

	outFile.open(fileName);
	if (!outFile)
		return false;

	for (int i = 0; i < (*size); i++)
	{
		contacts[i].getName(tempName);
		contacts[i].getEmail(tempEmail);
		outFile << tempName << ';' << tempEmail << std::endl;
	}
	outFile.close();
	return true;
}



bool Stack::loadFromFile(const char fileName[])
{
	std::ifstream inFile;
	char tempName[MAX_SIZE];
	char tempEmail[MAX_SIZE];

	inFile.open(fileName);
	if (!inFile)
		return false;

	inFile.get(tempName, MAX_SIZE, ';');
	while (!inFile.eof())
	{
		inFile.get();
		inFile.get(tempEmail, MAX_SIZE, '\n');
		inFile.ignore(MAX_SIZE, '\n');
	
		ContactInfo newContact(tempName, tempEmail);
		push(newContact);

		inFile.get(tempName, MAX_SIZE, ';');
	}
	inFile.close();
	return true;
}
