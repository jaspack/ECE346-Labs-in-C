#include"../../Utility/address_map_arm.h"
#include"../../Utility/JTAG.h"


int volatile* const startingAddress = (int*)0x1000;





int main(void)
{

	char message[] = "Type here: \0";

    

    while (1)
    {
        c = Cin();
        if (c != '\0')
            Cout(c);
    }

	return 0;
}


