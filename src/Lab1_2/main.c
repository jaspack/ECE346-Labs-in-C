#include "../address_map_arm.h"

int main(void) {

    //LDR R2, =LED_BASE 
    // base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;

    int pattern = 0b10100101;

    *(LED_ptr) = pattern;
    return 0;
}
