#include"../../Utility/address_map_arm.h"
#include"../../Utility/JTAG.h"


int volatile* const startingAddress = (int*)0x1000;




void main(void)
{
	char message[] = "Type here: \0";

    Print(message);
    
    while (1)
    {
        PrintChar(Read());
    }
}


