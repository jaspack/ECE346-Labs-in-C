#include "../../Utility/address_map_arm.h"

int main(void) {

    
    //  Base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;
    //  Pattern to be displayed on the LEDs
    int pattern = 0b10100101;
    //  Display Pattern
    *(LED_ptr) = pattern;
    return 0;
}
