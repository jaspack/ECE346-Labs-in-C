#include "address_map_arm.h"


// Create a pointer to the memory addresses for JP1 and JP7
volatile int* JP1 = (int*)JP1_BASE;
volatile int* JP7 = (int*)JP7_BASE;

//Configuration Settings \\
	
	// If your dipswitch is wired to:
		//JP1, set equal to one
		//JP7, set equal to zero
int isJP1theInput = 1;

// if  the seven segment display is:
	// A common anode display, set equal to one
	// A common cathode display, set equal to zero
int isCommonAnodeDisplay = 1;

int main(void)
{
	// JP7 memory address + 1 word
	// This sets the
	*(JP7 + 1) = 0xFFFF;
	*(JP7) = 0;
	int switchState;
	int leftSwitches, rightSwitches;
	int leftPattern, rightPattern;
	int fullPattern;

	int patterns[] =
	{
		0b00111111, 0b00000110, 0b01011011, 0b01001111,
		0b01100110, 0b01101101, 0b01111101, 0b00000111,
		0b01111111, 0b01100111, 0b01110111, 0b01111100,
		0b01011000, 0b01011110, 0b01111001, 0b01110001
	};


	while (1)
	{
		switchState = *(JP1) >> 8;
		leftSwitches = (switchState & 0b11110000) >> 4;
		rightSwitches = switchState & 0b00001111;
		leftPattern = patterns[leftSwitches];
		rightPattern = patterns[rightSwitches];
		fullPattern = ~((leftPattern << 8) | rightPattern);
		*(JP7) = fullPattern;
	}
	return 0;
}