#include "../../Utility/address_map_arm.h"

int main(void) {

    //  Base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;
    //  Base address of JP1
    volatile int* JP1 = (int*)JP1_BASE;
    //  Base address of push buttons
    volatile int* keys = (int*)KEY_BASE;

    while (1)
    {
        if ((*(keys) & 0b1) != 0)  // Check if key1 is pressed
            *(LED_ptr) = *(JP1);// if so, update the LEDs to the current state
    }
}
