#include "queue.h"

int main()
{
	Queue queue;
	ContactInfo contact1("Matthew Lidell", "mlidell@gmail.com");
	Party party1("Matt", 2, false, "None", true, contact1);
	Party party2("Mina", 4, true, "It is my birthday please sing to me", true, contact1);
	Party party3;
	queue.enqueue(party1);
	queue.enqueue(party2);
	//party3 = queue.dequeue();
	queue.peek();
	queue.display();
	return 0;
}
