#include"../../Utility/address_map_arm.h"
#include"../../Utility/JTAG.h"


/*
	• Capitalize each small-case letter (a-z) entered and 
		print out in the Terminal window. 
		(Other characters remain the same.)
	• The program will terminate if the key “ESC” (ASCII: 27) is entered
*/

char Capitalize(char c);

void main(void)
{
	// Sample message
	char message[] = "Capitalize: \0";
	Print(message);
	
	while (1)
	{
		char c = Read();
		if (c == 27)
			break;
		if (c != '\0')
		{
			c = Capitalize(c);
			PrintChar(c);
		}
	}
}


char Capitalize(char c)
{
	// Check if the character is lower case
	if ((c > 96) && (c < 123))
		// Convert to uppercase
		c -= 32;
	// Send the character
	return c;
}

