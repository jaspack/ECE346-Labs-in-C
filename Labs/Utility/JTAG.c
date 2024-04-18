#include"../../address_map_arm.h"

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