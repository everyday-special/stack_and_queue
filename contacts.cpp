/* Assignment: Project 2
 * Author: Matthew Lidell
 * Date: 10/17/2021
 * file: contacts.cpp
 * Purpose: Defines the ContactInfo member functions
 */
#include "contacts.h"

ContactInfo::ContactInfo()
/* Purpose: Default constructor for ContactInfo class
 * Parameters: None
 * Return: None
 */
{
	name = nullptr;
	email = nullptr;
}



ContactInfo::ContactInfo(const char name[], const char email[])
/* Purpose: Overloaded Constructor for ContactInfo class
 * Parameters:
 * 	-const char name[] - Name associated with ContactInfo
 * 	-const char email[] - Email associated with ContactInfo
 * Return: None
 */
{
	int strLen; // Stores length of input strings

	strLen = strlen(name);
	this->name = new char[++strLen];
	strcpy(this->name, name);
	strLen = strlen(email);
	this->email = new char[++strLen];
	strcpy(this->email, email);
}



ContactInfo::ContactInfo(const ContactInfo& refInfo)
/* Purpose: Copy Constructor for ContactInfo class
 * Pararmeters:
 * 	-ContactInfo& refInfo - ContactInfo being copied into new ContactInfo object
 * Returns: None
 */
{
	int strLen; // Stores length of input strings

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
/* Purpose: Overloaded assignment operator for ContactInfo objects
 * Parameters:
 * 	-const ContactInfo& srcInfo - ContactInfo object being copied
 * Return: None
 */
{
	int strLen; // Stores length of input string

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
/* Purpose: Checks if ContactInfo object has empty data fields
 * Parameters: None
 * Returns: bool - false if no data fields are empty, true if any data field is empty
 */
{
	if (!name || !email)
		return true;
	else
		return false;
}



void ContactInfo::getName(char result[])
/* Purpose: gets the name associated with the ContactInfo object
 * Parameters: char result[] - stores the name associated with the ContactInfo object
 * Return: None
 */
{
        strcpy(result, name);
}



void ContactInfo::getEmail(char result[])
/* Purpose: gets the email associated with the ContactInfo object
 * Parameters: char result[] - stores the email associated the with ContactInfo object
 * Return: None
 */
{       
        strcpy(result, email);
}



std::ostream& operator<<(std::ostream& out, const ContactInfo& contactInfo)
/* Purpose: Overloaded << operator for printing ContactInfo data
 * Parameters:
 * 	-std::ostream& out - ostream object
 * 	-const ContactInfo& contactInfo - ContactInfo object to be printed
 * Return: ostream object with data being printed
 */
{
	if (contactInfo.name)
		out << "Name: " << contactInfo.name << "\nEmail: " << contactInfo.email << std::endl;
	else
		out << "No informaton" << std::endl;
	return out;
}



ContactInfo::~ContactInfo()
/* Purpose: Destructor for ContactInfo class
 * Parameters: None
 * Return: None
 */
{
	delete [] name;
	name = nullptr;
	delete [] email;
	email = nullptr;
}
