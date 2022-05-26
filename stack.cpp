/* Purpose: Defines the menu class
 * Author: Matthew Lidell
 * Date: 10/31/2021
 * file: stack.cpp
 */
#include "stack.h"

Stack::Stack(int max)
/* Purpose: Constructor for stack objects
 * Parameters: int max - initial size to allocate for contacts array
 * Return: None
 */
{
	this->max = new int(max);
	size = new int(0);
	contacts = new ContactInfo[*(this->max)];
}



Stack::~Stack()
/* Purpose: Destructor for stack objects
 * Parameters: None
 * Return: None
 */
{
	delete max;
	max = nullptr;
	delete size;
	size = nullptr;
	delete [] contacts;
	contacts = nullptr;
}



void Stack::grow()
/* Purpose: Allocate a new array twice as large as the current array when it fills up
 * Parameters: None
 * Return: None
 */
{
	*max = 2 * *max;
	ContactInfo * temp = new ContactInfo[*max]; // new, larger array
	for (int i = 0; i < *size; i++)
		temp[i] = contacts[i];
	delete [] contacts;
	contacts = temp;
}



void Stack::peek()
/* Purpose: Display the ContactInfo object at the top of the stack or print "Stack is empty"
 * Parameters: None
 * Return: None
 */
{
	if ((*size) > 0)
		std::cout << contacts[*size - 1] << std::endl;
	else
		std::cout << "Stack is empty." << std::endl;
}



void Stack::display()
/* Purpose: Display all the ContactInfo objects in the stack, from top to bottom, or print "Stack is empty"
 * Parameters: None
 * Return: None
 */
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
/* Purpose: Adds ContactInfo object to the top of the stack
 * Parameters: ContactInfo newContact - new ContactInfo object to be added to the stack
 * Return: None
 */
{
	contacts[(*size)++] = newContact;
	if (*size == *max)
		grow();
}



ContactInfo Stack::pop()
/* Purpose: removes and returns the ContactInfo object at the top of the stack, or an empty ContactInfo object if the stack is empty. Empty ContactInfo objects can be detected using ContactInfo::isEmpty()
 * Parameters: None
 * Return: ContactInfo - object at the top of the stack
 */
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
/* Purpose: Returns the current size of the stack
 * Parameters: None
 * Return: int - current size of the stack
 */
{
	return *size;
}



bool Stack::saveToFile(const char fileName[])
/* Purpose: Saves the data in the current stack to a file
 * Parameters: const char fileName - name of the file to save the stack data to
 * Return: None
 */
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
/* Purpose: Loads data from text file into the stack
 * Parameters: const char fileName[] - name of the file containing data to be loaded into the stack
 * Return: None
 */
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
