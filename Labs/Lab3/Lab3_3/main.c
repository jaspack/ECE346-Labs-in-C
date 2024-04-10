#include "../../address_map_arm.h"

// Create a pointer to the memory addresses for JP1 and JP7
volatile int* keys = (int*)KEY_BASE;
volatile int* JP7 = (int*)JP7_BASE;

// if  the seven segment display is:
	// A common anode display, set equal to one
	// A common cathode display, set equal to zero
int isCommonAnodeDisplay = 1;
int patterns[] =
{
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01100111, 0b01110111, 0b01111100,
	0b01011000, 0b01011110, 0b01111001, 0b01110001
};

int main(void)
{
	// JP7 memory address + 1 word
	// This sets the
	*(JP7 + 1) = 0xFFFF;
	*(JP7) = 0;
	int switchState;
	int leftSwitches, rightSwitches;
	int leftPosition = 0;
	int rightPosition = 0;
	int leftPattern = patterns[0];
	int	rightPattern = patterns[0];
	int fullPattern;



	while (1)
	{
		if (*(keys) != 0)
			leftPosition++;
		if (leftPosition == 16)
		{
			leftPosition = 0;
			rightPosition++;
		}
		if (rightPosition == 16)
			rightPosition = 0;
		leftPattern = patterns[leftPosition];
		rightPattern = patterns[rightPosition];
		fullPattern = ((leftPattern << 8) | rightPattern);
		if (isCommonAnodeDisplay)
			fullPattern = ~fullPattern;
		*(JP7) = fullPattern;
	}
	return 0;
}