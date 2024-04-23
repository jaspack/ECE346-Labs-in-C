#include "../../Utility/address_map_arm.h"

int main(void) {

    // Base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;
    // Base address of the switches
    volatile int* SW_ptr = (int*)SW_BASE;
    

    while (1)
    {
        *(LED_ptr) = *(SW_ptr);// update the LEDs to the current state
    }
}
