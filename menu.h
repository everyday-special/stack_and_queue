#pragma once
#include "queue.h"
#include "stack.h"
#include "utils.h"

//const char fileName[] = "songs.txt";

class Menu
{
	public:
		Menu();
		~Menu();
		void run();

	private:
		//void load();
		//void save();
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
		Queue * queue;
		Stack * stack;
};
