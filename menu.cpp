#include "menu.h"

Menu::Menu()
{
	queue = new Queue();
	stack = new Stack(4);
	if (stack->loadFromFile(FILENAME))
		std::cout << "Loaded stack from file '" << FILENAME << "'." << std::endl;
	else
		std::cout << "Error loading stack from '" << FILENAME << "'." << std::endl;
}

Menu::~Menu()
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
{
	char reply;

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
{
	std::cout << "\nRestaurant options:" << std::endl;
	std::cout << "a) Add a new party to the Queue." << std::endl;
	std::cout << "b) Seat the next party in the Queue." << std::endl;
	std::cout << "c) View the next party in the Queue (without seating them)." << std::endl;
	std::cout << "d) View the entire Queue." << std::endl;
	std::cout << "e) View all the previous customers interested in promotional material." << std::endl;
	std::cout << "f) View the most recent customer." << std::endl;
	std::cout << "g) Send out promotional material to recent customers." << std::endl;
	std::cout << "q) Quit." << std::endl;
}


const char Menu::getReply()
{
	char reply; // Used to store and return user input

	std::cout << "Please make a selection from the options shown above: " << std::endl;
	std::cin >> reply;
	std::cin.ignore(MAX_SIZE, '\n');
	return reply;
}


void Menu::doCommand(const char reply)
{
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
{
	char partyName[MAX_SIZE];
	int partySize;
	char reply;
	char requests[MAX_SIZE];
	Party party;

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
		ContactInfo contact(promoName, promoEmail);
		party = Party(partyName, partySize, requests, contact);
	}
	else
		party = Party(partyName, partySize, requests);
	(*queue).enqueue(party);
}


void Menu::seatParty()
{
	if ((*queue).getSize() > 0)
	{
		Party party = (*queue).dequeue();
		std::cout << "\nNow seating:" << std::endl;
		std::cout << party << std::endl;
		if (party.wantsPromos())
		{
			ContactInfo contact = party.getContact();
			(*stack).push(contact);
			std::cout << "The following individual as agreed to receive promotional material:" << std::endl;
			std::cout << contact << std::endl;
		}
	}
	else
		std::cout << "There are no parties in the queue." << std::endl;	
}

void Menu::printQueue()
{
	std::cout << "There are " << (*queue).getSize() << " parties in the queue." << std::endl;
	if ((*queue).getSize() > 0)
		(*queue).display();
}

void Menu::nextInQueue()
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
{
	std::cout << "There are " << (*stack).getSize() << " individuals in the promotional stack." << std::endl;
	if ((*stack).getSize() > 0)
		(*stack).display();
}


void Menu::sendPromos()
{
	if ((*stack).getSize() > 0)
	{
		std::cout << "Sending promotional material to:" << std::endl;
		std::cout << (*stack).pop() << std::endl;
	}
	else
		std:: cout << "Stack is empty. No promotional material sent." << std::endl;
}
