/* Assignment: Project 2
 * Author: Matthew Lidell
 * Class: CS 260
 * Date: 10/17/2021
 * file: contacts.h
 * Purpose: Defines the ContactInfo class
 */
#pragma once
#include <cstring>
#include <ostream>

class ContactInfo
/*
 */
{
	public:
		ContactInfo();
		ContactInfo(const char name[], const char email[]);
		ContactInfo(const ContactInfo& refInfo);
		void operator = (const ContactInfo& srcInfo);
		//void setName(const char newName[]);
		//void setEmail(const char newEmail[]);
		~ContactInfo();
		
		friend std::ostream& operator<<(std::ostream& out, const ContactInfo& contactInfo);

	private:
		char * name;
		char * email;
};
