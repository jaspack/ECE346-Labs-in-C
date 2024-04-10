//	• Computing the summation of a list.
//	• The first value in the list indicates the number elements.

#include "../../address_map_arm.h";
void main(void)
{
	// list to be summed
	int LIST[11] = { 10, 43, 25, 0, 4, 31, 36, 0, 55, 13, 23 };
	
	// address to access the list
	volatile int* ans = (int*)0x1000;
	
	// Initialize the value to the memory address of the first element in the array
	*(ans) = &LIST;
	
	// start sorting

	// This boolean becomes true after we traverse the entire array and do not detect any elements out of order
	int isSorted = 0; 
	while (!isSorted)
	{
		// Set the value to true for now
		isSorted = 1;	

		// Itterate from the second element of the list to the last element of the list
		for (int i = 1; i < LIST[0]; i++)	
		{
			// Check if the current element and the next element are in order and switch them if they are not
			if (LIST[i] > LIST[i + 1])	
			{
				// We use a temporary value so that we don't lose the data while switching positions
				int temp = LIST[i];
				LIST[i] = LIST[i + 1];
				LIST[i + 1] = temp;
				// The current pass through the array had elements out of order so we set the boolean back to false
				isSorted = 0;
			}
		}
	}

	// keep the program running so we can pause and view the value
	while (1){}

}