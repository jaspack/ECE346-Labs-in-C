#include "../../address_map_arm.h"

int main(void) {

    // base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;

    volatile int* JP1 = (int*)JP1_BASE;
    
    volatile int* keys = (int*)KEY_BASE;

    while (1)
    {
        if ((*(keys) & 0b1) != 0)  // Check if key1 is pressed
            *(LED_ptr) = *(JP1);// if so, update the LEDs to the current state
    }
}
