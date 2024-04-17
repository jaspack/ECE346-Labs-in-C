#include"../../address_map_arm.h"
#include"num2str.h"


int volatile* const startingAddress = (int*)0x1000;
int volatile* const JTAG = (int*)JTAG_UART_BASE;

int numtoPrint = 24680;

/*******************************************************************************
 * Subroutine to send a character to the JTAG UART
 ******************************************************************************/
void Cout(char str[]) {

    char c = str[0];

    int i = 1;

    while (c != '\0')
    {
        *(JTAG) = c;
        c = str[i++];
    }
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

	char message[] = "Number to print: \0";
	Cout(message);

	char* num = Num2Str(numtoPrint); 
	Cout(num);

	return 0;
}


