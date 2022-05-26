/* Purpose: Defines the menu class
 * Author: Matthew Lidell
 * Date: 10/31/2021
 * file: menu.h
 */
#pragma once
#include "queue.h"
#include "stack.h"
#include "utils.h"


class Menu
/* UI For using the Restaurants queueing system and promotional stack
 * This class has 2 private data attributes:
 * 	-queue: pointer to the queue object that the user is populating
 * 	-stack: pointer to the stack object that the user is populating
 * This class has 3 public member functions:
 * 	-Default constructor
 * 	-Default destructor
 * 	-Run() - Runs the main menu loop allowing the user to view and select menu options for populating the queue and stack
 * This class has 10 private member functions:
 * 	-printMenu() - prints the menu options
 * 	-getReply() - gets the user input representing the menu selection
 * 	-doCommand() - perform the command based on the user input
 * 	-joinQueue() - get informaton for a party to be seated at the restaurant and add them to the queue
 * 	-seatParty() - seat the next party in the queue and add their contact info to the stack if they wanted to receive promotional material
 * 	-printQueue() - displays the entire queue from first to last
 * 	-nextInQueue() - displays the party at the front of the queue
 * 	-nextInStack() - displays the party at the top of the stack
 * 	-printStack() - displays the entire stack from top to bottom
 * 	-sendPromos() - sends promotional material to the individual at the top of the stack using stack.pop()
 */
{
	public:
		Menu();
		~Menu();
		void run();

	private:
		void printMenu();
		const char getReply();
		void doCommand(const char reply);
		void joinQueue();
		void seatParty();
		void printQueue();
		void nextInQueue();
		void nextInStack();
		void printStack();
		void sendPromos();
		Queue * queue; // Pointer to queue object
		Stack * stack; // Pointer to stack object
};
