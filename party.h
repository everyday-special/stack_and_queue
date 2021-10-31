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
/*
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
		char * name;
		int * size;
		char * requests;
		ContactInfo * contact;
};
