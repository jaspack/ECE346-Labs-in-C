#include "../../Utility/address_map_arm.h"

int main(void) {

    // base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;
    // base address of JP1
    volatile int* JP1 = (int*)JP1_BASE;


    while (1)
    {
        *(LED_ptr) = *(JP1);// update the LEDs to the current state
    }
}
