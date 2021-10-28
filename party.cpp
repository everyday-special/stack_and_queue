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
	haveRequests = nullptr;
	requests = nullptr;
	wantPromos = nullptr;
	contact = nullptr;
}

Party::Party(const char name[], const int size, const bool haveRequests, const char requests[], const bool wantPromos, const ContactInfo& contact)
{
	int strLen;

	strLen = strlen(name);
	this->name = new char[++strLen];
	strcpy(this->name, name);
	this->size = new int(size);
	this->haveRequests = new bool(haveRequests);
	strLen = strlen(requests);
	this->requests = new char[++strLen];
	strcpy(this->requests, requests);
	this->wantPromos = new bool(wantPromos);
	this->contact = new ContactInfo(contact);
}


Party::Party(const Party& refParty)
{
	int strLen;

	strLen = strlen(refParty.name);
	this->name = new char[++strLen];
	strcpy(this->name, refParty.name);
	this->size = new int(*(refParty.size));
	this->haveRequests = new bool(*(refParty.haveRequests));
	if (*(this->haveRequests))
	{
		strLen = strlen(refParty.requests);
		this->requests = new char[++strLen];
		strcpy(this->requests, refParty.requests);
	}
	else
	{
		this->requests = new char[5];
		strcpy(this->requests, "None\0");
	}
	this->wantPromos = new bool(*(refParty.wantPromos));
	if (*(this->wantPromos))
		this->contact = new ContactInfo(*(refParty.contact));
}

Party::~Party()
{
	delete [] name;
	name = nullptr;
	delete size;
	size = nullptr;
	delete haveRequests;
	haveRequests = nullptr;
	delete [] requests;
	requests = nullptr;
	delete wantPromos;
	wantPromos = nullptr;
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
	this->haveRequests = new bool(*(srcParty.haveRequests));
	strLen = strlen(srcParty.requests);
	this->requests = new char[++strLen];
	strcpy(this->requests, srcParty.requests);
	this->wantPromos = new bool(*(srcParty.wantPromos));
	this->contact = new ContactInfo(*(srcParty.contact));
}


std::ostream& operator<<(std::ostream& out, const Party& Party)
{
	out << "Party Name: " << Party.name << std::endl;
	out << "Size: " << *(Party.size) << std::endl;
	out << "Special Requests: ";
	if (*(Party.haveRequests))
		out << Party.requests << std::endl;
	else
		out << "None." << std::endl;
	if (*(Party.wantPromos))
		out << *(Party.contact) << std::endl;
	else
		out << "Declined promotional material." << std::endl;
	return out;
}
