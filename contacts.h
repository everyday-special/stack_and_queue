/* Assignment: Project 2
 * Author: Matthew Lidell
 * Date: 10/17/2021
 * file: contacts.h
 * Purpose: Defines the ContactInfo class
 */
#pragma once
#include <cstring>
#include <ostream>

class ContactInfo
/* Class representing an individuals contact information for promotional purposes
 * This class has 2 private data members:
 * 	- name - cstring representing the persons name
 * 	- email - cstring representing the persons email
 * This class has 8 public member functions:
 * 	- Default constructor
 * 	- Constructor that takes cstrings to populate name and email
 * 	- Copy Constructor
 * 	- Assignment operator
 * 	- getName() - gets the ContactInfo's name
 * 	- getEmail() - gets the email associated with the ContactInfo
 * 	- Default destructor
 * 	- isEmpty() - returns true if name and email are set, false if they're unset
 * This class has 1 friend function:
 * 	- overloaded << operator for printing ContactInfo data
 */
{
	public:
		ContactInfo();
		ContactInfo(const char name[], const char email[]);
		ContactInfo(const ContactInfo& refInfo);
		void operator = (const ContactInfo& srcInfo);
		void getName(char newName[]);
		void getEmail(char newEmail[]);
		~ContactInfo();
		bool isEmpty();
		
		friend std::ostream& operator<<(std::ostream& out, const ContactInfo& contactInfo);

	private:
		char * name; // pointer to cstring for storing the name
		char * email; // pointer to cstring for storing the email
};
