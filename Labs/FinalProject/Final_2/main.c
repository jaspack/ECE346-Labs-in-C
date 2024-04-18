#include"../../Utility/address_map_arm.h"
#include"sort.h"

int* startingAddress = (int*)0x1000;
int volatile* const switches = (int*)SW_BASE;
int volatile* const keys = (int*)KEY_BASE;

/*
• Make the sorting algorithm a separate .s file (subroutine).
• Include the subroutine in the main file (i.e. Final2.s) and call (instruction
	BL) the subroutine to perform sorting, passing the argument (memory
	location of the data) through the stack (register SP).
• Load the data into memory from the file list2.csv starting at 0x1000.
• After sorting, take a screenshot of sorted results to prove your
	subroutine works correctly.
*/


void main(void)
{
	BubbleSort(startingAddress);
}