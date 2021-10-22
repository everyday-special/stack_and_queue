#include "stack.h"

int main()
{
	Stack stack;
	ContactInfo contact1("Matthew Lidell", "mlidell@gmail.com");
	ContactInfo contact2("Test McTest", "mctest@testes.text");
	stack.push(contact2);
	stack.push(contact1);
	stack.push(contact2);
	stack.push(contact2);
	stack.push(contact1);
	stack.peek();
	stack.display();
	return 0;
}
