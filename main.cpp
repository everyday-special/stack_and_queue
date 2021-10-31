/* Purpose: Definition of main function
 * Author: Matthew Lidell
 * CS 260 Project 2
 * Date: 10/31/2021
 * file: main.cpp
 */
#include "menu.h"

int main(int argc, char ** argv, char ** envp)
{
	Menu menu; // Instantiate menu object
	menu.run(); // Run the menu main loop
	return 0;
}
