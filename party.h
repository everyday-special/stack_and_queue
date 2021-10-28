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
		Party(const char name[], const int size, const bool haveRequests, const char requests[], const bool wantPromos, const ContactInfo& contact);
		Party(const Party& refParty);
		~Party();
		void operator = (const Party& srcParty);	

		friend std::ostream& operator<<(std::ostream& out, const Party& party);

	private:
		char * name;
		int * size;
		bool * haveRequests;
		char * requests;
		bool * wantPromos;
		ContactInfo * contact;
};
