//	• Computing the summation of a list.
//	• The first value in the list indicates the number elements.

#include "../../Utility/address_map_arm.h"
void main(void)
{
	// list to be summed
	int LIST[11] = { 10, 43, 25, 0, -4, 31, -36, 0, 55, -13, 23 };
	
	// address to access the answer of the summation
	volatile int* ans = (int*)0x1000;
	
	// Initialize the value of the answer to zero
	*(ans) = 0;
	
	// skip the first number and add all remaining numbers to the final answer
	for (int i = 1; i < LIST[0] +1; i++)
	{
		*(ans) += LIST[i];
	}

	// keep the program running so we can pause and view the value
	while (1){}

}