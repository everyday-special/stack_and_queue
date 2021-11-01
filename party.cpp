/* Assignment: Project 2
 * Author: Matthew Lidell
 * Class: CS 260
 * Date: 10/17/2021
 * file: party.cpp
 * Purpose: Defines the member functions for the party class
 */
#include "party.h"

Party::Party()
/* Purpose: Default constructor for party class
 * Parameters: None
 * Return: None
 */
{
	name = nullptr;
	size = nullptr;
	requests = nullptr;
	contact = nullptr;
}



Party::Party(const char name[], const int size, const char requests[], const ContactInfo& contact)
/* Purpose: Overloaded constructor for parties with contactInfo object
 * Parameters:
 * 	-const char name[] - cstring for the name associated with the party object
 * 	-const int size - int representing the size of the party
 * 	-const char requests[] - cstring for the special seating requests for the party
 * 	-const ContactInfo& contact - ContactInfo object associated with the party object
 * Return: None
 */
{
	int strLen; // Holds length of parameter cstrings to dynamically allocate party cstrings

	strLen = strlen(name);
	this->name = new char[++strLen];
	strcpy(this->name, name);
	this->size = new int(size);
	strLen = strlen(requests);
	this->requests = new char[++strLen];
	strcpy(this->requests, requests);
	this->contact = new ContactInfo(contact);
}



Party::Party(const char name[], const int size, const char requests[])
/* Purpose: Overloaded constructor for parties without contactInfo object
 * Parameters:
 *      -const char name[] - cstring for the name associated with the party object
 *      -const int size - int representing the size of the party
 *      -const char requests[] - cstring for the special seating requests for th
e party
ty object
 * Return: None
 */
{
	int strLen; // Holds length of parameter cstrings to dynamically allocate party cstrings

	strLen = strlen(name);
	this->name = new char[++strLen];
	strcpy(this->name, name);
	this->size = new int(size);
	strLen = strlen(requests);
	this->requests = new char[++strLen];
	strcpy(this->requests, requests);
	this->contact = nullptr;
}



Party::Party(const Party& refParty)
/* Purpose: Copy Constructor for party objects
 * Parameters: const Party& refParty - party object being copied into new object
 * Return: None
 */
{
	int strLen; // Holds length of parameter cstrings to dynamically allocate party cstrings

	if (refParty.name)
	{
		strLen = strlen(refParty.name);
		this->name = new char[++strLen];
		strcpy(this->name, refParty.name);
	}
	else
		this->name = nullptr;
	if (refParty.size)
		this->size = new int(*(refParty.size));
	else
		this->size = nullptr;
	if (refParty.requests)
	{
		strLen = strlen(refParty.requests);
		this->requests = new char[++strLen];
		strcpy(this->requests, refParty.requests);
	}
	if (refParty.contact)
		this->contact = new ContactInfo(*(refParty.contact));
	else
		this->contact = nullptr;
}



Party::~Party()
/* Purpose: Destructor for party objects
 * Parameters: None
 * Return: None
 */
{
	delete [] name;
	name = nullptr;
	delete size;
	size = nullptr;
	delete [] requests;
	requests = nullptr;
	delete contact;
	contact = nullptr;
}



void Party::operator = (const Party& srcParty)
/* Purpose: Assignment operator for party objects
 * Parameters: const Party& srcParty - party object being copied into new party object
 * Return: None
 */
{
	int strLen; // Holds length of parameter cstrings to dynamically allocate party cstrings

	if (srcParty.name)
	{
		strLen = strlen(srcParty.name);
		this->name = new char[++strLen];
		strcpy(this->name, srcParty.name);
	}
	else
		this->name = nullptr;
	if (srcParty.size)
	{
		this->size = new int(*(srcParty.size));
	}
	else
		this->size = nullptr;
	if (srcParty.requests)
	{
		strLen = strlen(srcParty.requests);
		this->requests = new char[++strLen];
		strcpy(this->requests, srcParty.requests);
	}
	else
		this->requests = nullptr;
	if (srcParty.contact)
	{
		delete this->contact;
		this->contact = new ContactInfo(*(srcParty.contact));
	}
	else
	{
		delete this->contact;
		this->contact = nullptr;
	}
}



bool Party::wantsPromos()
/* Purpose: checks if party has contact info associated with it.
 * Parameters: None
 * Return: True if party has a contactInfo object, false if not
 */
{
	if (this->contact == nullptr)
		return false;
	else
		return true;
}



ContactInfo Party::getContact()
/* Purpose: gets the contactInfo object associated with the party object
 * Parameters: None
 * Return: ContactInfo - contactInfo object associated with the party object, or empty ContactInfo object if there is none
 */
{
	if (!contact)
	{
		ContactInfo contact = ContactInfo(); // Empty contact object if no contactInfo object is associated with the party
		return contact;
	}
	else
		return *(this->contact);
}



bool Party::isEmpty()
/* Purpose: Checks if the party object has any data associated with it
 * Parameters: None
 * Return: True if name, size, or request data is missing, false if all 3 data is present
 */
{
	if (!name || !size || !requests)
		return true;
	else
		return false;
}



std::ostream& operator<<(std::ostream& out, const Party& Party)
/* Purpose: Overloaded << operator for printing party object data
 * Parameters:
 * 	-std::ostream& out - ostream object for printing data
 * 	-const Party& Party - party object whose data is being printed
 * Return: std::ostream& - ostream object with data being printed
 */
{
	out << "Party Name: " << Party.name << std::endl;
	out << "Size: " << *(Party.size) << std::endl;
	out << "Special Requests: ";
	out << Party.requests << std::endl;
	if (Party.contact)
		out << *(Party.contact) << std::endl;
	else
		out << "Declined promotional material." << std::endl;
	return out;
}
