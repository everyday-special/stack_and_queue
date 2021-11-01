/* Assignment: Project 2
 * Author: Matthew Lidell
 * Class: CS 260
 * Date: 10/17/2021
 * file: party.h
 * Purpose: Defines the party class
 */
#pragma once
#include "contacts.h"

class Party
/* Class representing a party waiting to be seated at the restaurant
 * This class has 4 private data members:
 * 	- name - cstring containing the name of the party
 * 	- size - int containing the size of the party
 * 	- requests - cstring containing any special seating requests the party needs\
 * 	- contact - stores a ContactInfo object if the party opted into receivin promotional material
 * This class has 9 public member functions:
 * 	- Default constructor
 * 	- Overloaded constructor without contact info
 * 	- Overloaded constructor with contact info
 * 	- Copy Constructor
 * 	- Default Destructor
 * 	- Assignment operator
 * 	- wantsPromos() - returns true if the party has contact info associated with it, false if not
 * 	- getContact() - returns the ContactInfo object associated with the party object
 * 	- isEmpty() - checks if party has data associated with it
 * This class has 1 friend function:
 * 	-Overloaded << operator
 */
{
	public:
		Party();
		Party(const char name[], const int size, const char requests[], const ContactInfo& contact);
		Party(const char name[], const int size, const char requests[]);
		Party(const Party& refParty);
		~Party();
		void operator = (const Party& srcParty);
		bool wantsPromos();
		ContactInfo getContact();
		bool isEmpty();

		friend std::ostream& operator<<(std::ostream& out, const Party& party);

	private:
		char * name; // stores the name associated with the party
		int * size; // stores the size of the party
		char * requests; // stores the special seating requests
		ContactInfo * contact; // stores the contact information if they opted into receiving promotional material
};
