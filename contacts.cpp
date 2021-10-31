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

	if (refInfo.name)
	{
		strLen = strlen(refInfo.name);
		this->name = new char[++strLen];
		strcpy(this->name, refInfo.name);
	}
	else
		this->name = nullptr;
	if (refInfo.email)
	{
		strLen = strlen(refInfo.email);
		this->email = new char[++strLen];
		strcpy(this->email, refInfo.email);
	}
	else
		this->email = nullptr;
}

void ContactInfo::operator = (const ContactInfo& srcInfo)
{
	int strLen;

	if (srcInfo.name)
	{
		strLen = strlen(srcInfo.name);
		this->name = new char[++strLen];
		strcpy(this->name, srcInfo.name);
	}
	else
		this->name = nullptr;
	if (srcInfo.email)
	{
		strLen = strlen(srcInfo.email);
		this->email = new char[++strLen];
		strcpy(this->email, srcInfo.email);
	}
	else
		this->email = nullptr;
}


bool ContactInfo::isEmpty()
{
	if (!name)
		return false;
	else
		return true;
}


void ContactInfo::getName(char result[])
{
        strcpy(result, name);
}

void ContactInfo::getEmail(char result[])
{       
        strcpy(result, email);
}



std::ostream& operator<<(std::ostream& out, const ContactInfo& contactInfo)
{
	if (contactInfo.name)
		out << "Name: " << contactInfo.name << "\nEmail: " << contactInfo.email << std::endl;
	else
		out << "No informaton" << std::endl;
	return out;
}



ContactInfo::~ContactInfo()
{
	delete [] name;
	name = nullptr;
	delete [] email;
	email = nullptr;
}
