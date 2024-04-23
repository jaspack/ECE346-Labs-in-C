#include"../../Utility/address_map_arm.h"
#include"../../Utility/JTAG.h"
#include"num2str.h"

void main(void)
{
// This is the number we're converting to a string
	int numtoPrint = 24680;

// Sample message
	char message[] = "Number to print: \0";
	Print(message);

// Printing the result of the function
	char* num = Num2Str(numtoPrint); 
	Print(num);
}


