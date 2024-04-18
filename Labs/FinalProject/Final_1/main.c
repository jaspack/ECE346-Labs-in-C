#include"../../Utility/address_map_arm.h"


int volatile* const startingAddress = (int*)0x1000;
int volatile* const switches = (int*)SW_BASE;
int volatile* const keys = (int*)KEY_BASE;

void main(void)
{
	startingAddress[0] = 1;
	while (1)
	{
		int keyPressed = (*(keys) & 2);
		if (!keyPressed)
			continue;
		int switchState = *(switches);
		for (int i = 1; i < 16; i++)
		{
			startingAddress[i] = 0;
		}
		if (switchState == 0)
			continue;
		startingAddress[1] = 1;
		for (int j = 2; j < switchState + 1; j++)
		{
			startingAddress[j] = startingAddress[j - 1] + startingAddress[j - 2];
		}

	}
}