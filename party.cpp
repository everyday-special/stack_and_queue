/* Assignment: Project 2
 * Author: Matthew Lidell
 * Class: CS 260
 * Date: 10/17/2021
 * file: party.cpp
 * Purpose: Defines the member functions for the party class
 */
#include "party.h"

Party::Party()
{
	name = nullptr;
	size = nullptr;
	requests = nullptr;
	contact = nullptr;
}

Party::Party(const char name[], const int size, const char requests[], const ContactInfo& contact)
{
	int strLen;

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
{
	int strLen;

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
{
	int strLen;

	strLen = strlen(refParty.name);
	this->name = new char[++strLen];
	strcpy(this->name, refParty.name);
	this->size = new int(*(refParty.size));
	strLen = strlen(refParty.requests);
	this->requests = new char[++strLen];
	strcpy(this->requests, refParty.requests);
	if (refParty.contact)
		this->contact = new ContactInfo(*(refParty.contact));
	else
		this->contact = nullptr;
}

Party::~Party()
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
{
	int strLen;

	strLen = strlen(srcParty.name);
	this->name = new char[++strLen];
	strcpy(this->name, srcParty.name);
	this->size = new int(*(srcParty.size));
	strLen = strlen(srcParty.requests);
	this->requests = new char[++strLen];
	strcpy(this->requests, srcParty.requests);
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
{
	if (this->contact == nullptr)
		return false;
	else
		return true;
}



ContactInfo Party::getContact()
{
	return *(this->contact);
}



bool Party::isEmpty()
{
	if (!name)
		return false;
	else
		return true;
}



std::ostream& operator<<(std::ostream& out, const Party& Party)
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
