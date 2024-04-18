#include"../../address_map_arm.h"

int volatile* const JTAG = (int*)JTAG_UART_BASE;

void PrintChar(char c)
{
    *(JTAG) = c;
}


void Print(char str[])
{
    int size = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '\0')
            return;
        PrintChar(str[i]);
    }
}

void Println(char str[])
{
    Print(str);
    PrintChar('\n');
}


char Read(void) 
{
    int dataRegister;
    // read the JTAG_UART data register
    dataRegister = *(JTAG);

    // Masking with position of Rvalid to see if there is a new character available
    if (dataRegister & 0x00008000)
        return ((char)dataRegister & 0xFF);
    else
        return ('\0');
}