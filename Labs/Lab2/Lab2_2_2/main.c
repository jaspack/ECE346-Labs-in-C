#include "../../Utility/address_map_arm.h"

int main(void) {

    // base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;
    // base address of JP1
    volatile int* JP1 = (int*)JP1_BASE;

    // Initialize values
    int A;
    int B = 4;
    int C;
    int D = 6;
    int ans;

    while (1)
    {
        A = *(JP1) & 0b11110000; // masking to get A
        
        C = *(JP1) & 0b1111;     // masking to get C
        
        ans = (A * B) + (C * D);    // Calculation
        
        *(LED_ptr) = ans; // displays the answer to the on board LEDs

    }

}
