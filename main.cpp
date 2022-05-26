/* Purpose: Definition of main function
 * Author: Matthew Lidell
 * Date: 10/31/2021
 * file: main.cpp
 */
#include "menu.h"

int main(int argc, char ** argv, char ** envp)
/* Purpose: Main program loop
 * Parameters:
 * 	-int argc - number of command line arguments
 * 	-char ** argv - array of cstrings of all the commandline arguments
 * 	-char ** envp - array of cstrings of all the environment variables
 * Returns:
 * 	-int- returns 0 if program exits without issues
 */
{
	Menu menu; // Instantiate menu object
	menu.run(); // Run the menu main loop
	return 0;
}
