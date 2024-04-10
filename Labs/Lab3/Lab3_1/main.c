#include "../../address_map_arm.h

int main(void) 
{
    int COMPRESSED[] = 
    {
        3,
        0xEECE,
        2,
        0xF00D,
        4,
        0xCAFE,
        1,
        0xABCD,
        0
    }

    int DECOMPRESSED[10];

    int index = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < COMPRESSED[i]; j++)
        {
            DECOMPRESSED[index] = COMPRESSED[i + 1];
            index++;
        }
        i++;
    }
}


/*
    Design a program to decompress 
    the data sequence saved 
    in the data section (COMPRESSED)
    and store the decompressed data to the 
    corresponding memory location (DECOMPRESSED)
    as a sequence. ‘0’ is used to denote the end of the
    data sequence in the compressed representation.
    Check the memory location where the
    decompressed data saved at (e.g. R3) and take a
    screenshot of the decompressed results in the
    MEMORY page.
*/