#include "../../address_map_arm.h"

int main(void) {

    // base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;

    // LED right bound
    int rightBound = 1;

    // LED left bound
    int leftBound = 0b10000000;

    // for delay
    int DELAY = 0X02FFFFFF;

    int currentState = rightBound;

    while (1)
    {
        if (currentState != leftBound*2) // Check to see if the left bound has been reached
        {
            currentState = currentState << 1; // If not, shift the current state to the left
        }
        else
        {
            currentState = rightBound; // If it is, set current state back to the right bound
        }
        
        *(LED_ptr) = currentState;// update the LEDs to the current state
        
        for (int i = 0; i < DELAY; i++) {} // Delay

    }
}
