#include "../../Utility/address_map_arm.h"

int main(void) {

    // base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;

    int A = 15;
    int B = 4;
    int C = 5;
    int D = 6;

    int ans = (A * B) + (C * D);

    LED_ptr = ans; // displays the answer to the on board LEDs
}
