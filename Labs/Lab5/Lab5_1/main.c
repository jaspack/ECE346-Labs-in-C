#include"../../Utility/address_map_arm.h"
#include"../../Utility/JTAG.h"


int volatile* const startingAddress = (int*)0x1000;

/*******************************************************************************
 * Subroutine to send a character to the JTAG UART
 ******************************************************************************/
void Cout(char c) {
    
        *(JTAG) = c;
}

char Cin() {
    int dataRegister;
    // read the JTAG_UART data register
    dataRegister = *(JTAG); 

    // Masking with position of Rvalid to see if there is a new character available
    if (dataRegister & 0x00008000)   
        return ((char)dataRegister & 0xFF);
    else
        return ('\0');
}


int main(void)
{

	char message[] = "Type here: \0";

    char c = 'T';

    int i = 1;

    while (c != '\0')
    {
        Cout(c);
        c = message[i++];
    }

    while (1)
    {
        c = Cin();
        if (c != '\0')
            Cout(c);
    }

	return 0;
}


