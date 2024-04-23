#include "../../address_map_arm.h

int main(void) 
{
    //  Initialize the compressed data
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
    
    //  Allocate memory for the decompressed data
    int DECOMPRESSED[10];

    //  Decompress data
    int index = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < COMPRESSED[i]; j++)
        {
            DECOMPRESSED[index] = COMPRESSED[i + 1];
            index++;
        }
        // Increment i twice per iteration
        i++;
    }
}