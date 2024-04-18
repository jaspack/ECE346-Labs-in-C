#include "../../Utility/address_map_arm.h"

void interval_timer_ISR()
{
    volatile int * interval_timer_ptr = (int *)TIMER_BASE;
    *(interval_timer_ptr) = 0; // Clear the interrupt

    int* LED = (int*)LED_BASE;

    unsigned int cur = *LED;
    unsigned int flip = 0b11111111;
    flip = cur ^ flip;
    *LED = flip;
}

