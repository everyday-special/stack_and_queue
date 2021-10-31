/* Assignment: Project 2
 * Author: Matthew Lidell
 * Class: CS 260
 * Date: 10/17/2021
 * file: contacts.cpp
 * Purpose: Defines the ContactInfo member functions
 */
#include "contacts.h"

ContactInfo::ContactInfo()
{
	name = nullptr;
	email = nullptr;
}

ContactInfo::ContactInfo(const char name[], const char email[])
{
	int strLen;

	strLen = strlen(name);
	this->name = new char[++strLen];
	strcpy(this->name, name);
	strLen = strlen(email);
	this->email = new char[++strLen];
	strcpy(this->email, email);
}

ContactInfo::ContactInfo(const ContactInfo& refInfo)
{
	int strLen;

	strLen = strlen(refInfo.name);
	this->name = new char[++strLen];
	strcpy(this->name, refInfo.name);
	strLen = strlen(refInfo.email);
	this->email = new char[++strLen];
	strcpy(this->email, refInfo.email);
}

void ContactInfo::operator = (const ContactInfo& srcInfo)
{
	int strLen;

	strLen = strlen(srcInfo.name);
	this->name = new char[++strLen];
	strcpy(this->name, srcInfo.name);
	strLen = strlen(srcInfo.email);
	this->email = new char[++strLen];
	strcpy(this->email, srcInfo.email);
}


bool ContactInfo::isEmpty()
{
	if (!name)
		return false;
	else
		return true;
}


std::ostream& operator<<(std::ostream& out, const ContactInfo& contactInfo)
{
	out << "Name: " << contactInfo.name << "\nEmail: " << contactInfo.email << std::endl;
	return out;
}



ContactInfo::~ContactInfo()
{
	delete [] name;
	name = nullptr;
	delete [] email;
	email = nullptr;
}
