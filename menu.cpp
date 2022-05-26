/* Purpose: Defines the menu class member fuctions
 * Author: Matthew Lidell
 * Date: 10/31/2021
 * file: menu.cpp
 */
#include "menu.h"

Menu::Menu()
/* Purpose: Default constructor for menu. Instantiates the queue, the stack with a starting maximum size of 4, and loads song data from file
 * Parameters: None
 * Return: None
 */
{
	queue = new Queue(); // Instantiate queue object
	stack = new Stack(4); // Instantiate stack object with initial maximum size of 4
	if (stack->loadFromFile(FILENAME))
		std::cout << "Loaded stack from file '" << FILENAME << "'." << std::endl;
	else
		std::cout << "Error loading stack from '" << FILENAME << "'." << std::endl;
}



Menu::~Menu()
/* Purpose: Default destructor for Menu. Saves the song list before deallocating the queue and stack.
 * Parameters: None
 * Return: None
 */
{
	if (stack->saveToFile(FILENAME))
		std::cout << "Saved stack to file '" << FILENAME << "'." << std::endl;
	else
		std::cout << "Error saving stack to '" << FILENAME << "'." << std::endl;
	delete queue;
	queue = nullptr;
	delete stack;
	stack = nullptr;
}



void Menu::run()
/* Purpose: Runs the menu loop of 1) printing the menu, 2) getting user selection, and 3) performing the requested action until the user presses 'q' to quit
 * Parameters: None
 * Return None
 */
{
	char reply; // Used to store user input

	std::cout << "Welcome to the Restaurant!" << std::endl;

	do
	{
		printMenu();
		reply = getReply();
		doCommand(reply);
	}
	while (reply != 'q');
}



void Menu::printMenu()
/* Purpose: Prints the menu options
 * Parameters: None
 * Return: None
 */
{
	std::cout << "\nRestaurant options:" << std::endl;
	std::cout << "a) Add a new party to the Queue. (enqueue)" << std::endl;
	std::cout << "b) Seat the next party in the Queue. (dequeue and push to stack)" << std::endl;
	std::cout << "c) View the next party in the Queue (without seating them). (peek queue)" << std::endl;
	std::cout << "d) View the entire Queue. (display queue)" << std::endl;
	std::cout << "e) View all the previous customers interested in promotional material. (display stack)" << std::endl;
	std::cout << "f) View the most recent customer interested in receiving promotional material. (peek stack)" << std::endl;
	std::cout << "g) Send out promotional material to the most recent customer who opted in. (pop stack)" << std::endl;
	std::cout << "q) Quit.\n" << std::endl;
}



const char Menu::getReply()
/* Purpose: Prompts user for their menu option selecton
 * Parameters: None
 * Return: character representing their menu selection
 */
{
	char reply; // Used to store and return user input

	std::cout << "Please make a selection from the options shown above: " << std::endl;
	std::cin >> reply;
	std::cin.ignore(MAX_SIZE, '\n');
	return reply;
}



void Menu::doCommand(const char reply)
/* Purpose: Performs command based on the reply parameter
 * Parameters: reply - character representing the menu selection and associated with one of the commands
 * Return: None
 */
{
	std::cout << std::endl;
	switch (reply)
	{
		case 'a':
			joinQueue();
			break;
		case 'b':
			seatParty();
			break;
		case 'c':
			nextInQueue();
			break;
		case 'd':
			printQueue();
			break;
		case 'e':
			printStack();
			break;
		case 'f':
			nextInStack();
			break;
		case 'g':
			sendPromos();
			break;
		case 'q':
			std::cout << "Exiting Restaurant Menu." << std::endl;
			break;
		default:
			std::cout << "(" << reply << ") is not a valid option. Please try again." << std::endl;
	}
}



void Menu::joinQueue()
/* Purpose: Prompts user for the information about the party to be seated and then adds a party object with that information to the queue
 * Parameters: None
 * Return: None
 */
{
	char partyName[MAX_SIZE]; // Stores the party's name
	int partySize; // Stores the party size
	char reply; // Stores the user's reply to special seating requests and promotional material
	char requests[MAX_SIZE]; // Stores the seating requests
	Party party; // Stores the party to be added to the queue

	std::cout << "\nPlease enter a name for the party: ";
	getString(partyName);
	std::cout << "Please eneter the size of the party: ";
	partySize = getInt();
	std::cout << "Do you have any special seating requests?" << std::endl;
	std::cout << "a) No requests" << std::endl;
	std::cout << "b) Wheel chair" << std::endl;
	std::cout << "c) High chair" << std::endl;
	std::cout << "d) Wheel chair and High chair" << std::endl;
	reply = getReply();
	while (reply != 'a' && reply != 'b' && reply != 'c' && reply != 'd')
	{
		std::cout << "(" << reply << ") is not a valid option. Please enter a seating option (a, b, c or d): ";
		reply = getReply();
	}
	switch (reply)
	{
		case 'a':
			strcpy(requests, "None.");
			break;
		case 'b':
			strcpy(requests, "Wheel chair.");
			break;
		case 'c':
			strcpy(requests, "High chair.");
			break;
		case 'd':
			strcpy(requests, "Wheel chair and high chair.");
			break;
	}
	std::cout << "Do you want to recieve promotional material via email? Please enter 'y' for yes and 'n' for no: ";
	reply = getReply();
	while (reply != 'y' && reply != 'n')
	{
		std::cout << "Please enter 'y' for yes or 'n' for no: ";
		reply = getReply();
	}
	if (reply == 'y')
	{
		char promoName[MAX_SIZE];
		char promoEmail[MAX_SIZE];
		std::cout << "Please enter your full name for receiving promotional material: ";
		getString(promoName);
		std::cout << "Please enter your email address for receiving promotional material: ";
		getString(promoEmail);
		ContactInfo contact(promoName, promoEmail); // Stores the party's contact info if they opted into receiving promotional material
		party = Party(partyName, partySize, requests, contact);
	}
	else
		party = Party(partyName, partySize, requests);
	(*queue).enqueue(party);
}



void Menu::seatParty()
/* Purpose: Dequeues the party at the front of the queue. If the queue is empty, say so and do nothing. If the party at the front requested promotional material, add them to the promotional stack
 * Parameters: None
 * Return: None
 */
{
	if ((*queue).getSize() > 0)
	{
		Party party = (*queue).dequeue();
		std::cout << "\nNow seating:" << std::endl;
		std::cout << party << std::endl;
		if (party.wantsPromos())
		{
			ContactInfo contact = party.getContact(); // Stores the contact info to be added to the stack if they opted in to receiving promotional material
			(*stack).push(contact);
			std::cout << "The following individual as agreed to receive promotional material:" << std::endl;
			std::cout << contact << std::endl;
		}
	}
	else
		std::cout << "There are no parties in the queue." << std::endl;	
}



void Menu::printQueue()
/* Purpose: Prints the size of the queue and the information for each party in the queue.
 * Parameters: None
 * Return: None
 */
{
	std::cout << "There are " << (*queue).getSize() << " parties in the queue." << std::endl;
	if ((*queue).getSize() > 0)
		(*queue).display();
}



void Menu::nextInQueue()
/* Purpose: Prints the information of the party at the front of the queue
 * Parameters: None
 * Return: None
 */
{
	if ((*queue).getSize() > 0)
	{
		std::cout << "The following party will be seated next:" << std::endl;
		(*queue).peek();
	}
	else
		std::cout << "There are no parties in the queue." << std::endl;
}



void Menu::nextInStack()
/* Purpose: Prints the contact information of the individual at the top of the stack
 * Parameters: None
 * Return: None
 */
{
	if ((*stack).getSize() > 0)
	{
		std::cout << "The following individual will is next in the promotional material stack:" << std::endl;
		(*stack).peek();
	}
	else
		std::cout << "Stack is empty." << std::endl;
}



void Menu::printStack()
/* Purpose: Prints the current size of the stack and the information of everyone in the stack from top to bottom
 * Parameters: None
 * Return: None
 */
{
	std::cout << "There are " << (*stack).getSize() << " individuals in the promotional stack." << std::endl;
	if ((*stack).getSize() > 0)
		(*stack).display();
}



void Menu::sendPromos()
/* Purpose: Removes the individual at the top of the stack from the stack, representing sending them promotional material
 * Parameters: None
 * Return: None
 */
{
	if ((*stack).getSize() > 0)
	{
		std::cout << "Sending promotional material to:" << std::endl;
		std::cout << (*stack).pop() << std::endl;
	}
	else
		std:: cout << "Stack is empty. No promotional material sent." << std::endl;
}
