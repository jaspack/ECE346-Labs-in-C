#include"../../Utility/address_map_arm.h"


int volatile* const startingAddress = (int*)0x1000;


int main(void)
{
	*startingAdress = 0x1234;

	return 0;
}