#include "../address_map_arm.h"

int main(void) {

    //LDR R2, =LED_BASE 
    // base address of LED lights
    volatile int* LED_ptr = (int*)LED_BASE;

    //LDR R3, =0b00000001 
    // LED right bound
    int rightBound = 1;

    // LDR R4, =0b10000000 
    // LED left bound
    int leftBound = 0b10000000;

    // LDR R5, =0X02FFFFFF 
    // for delay
    int DELAY = 0X02FFFFFF;

    int currentState = leftBound;

    while (1)
    {
        if (currentState != 1) // Check to see if the right bound has been reached
        {
            currentState = currentState >> 1; // If not, shift the current state to the right
        }
        else
        {
            currentState = leftBound; // If it is, set current state back to the left bound
        }

        *(LED_ptr) = currentState;// update the LEDs to the current state

        for (int i = 0; i < DELAY; i++) {} // Delay

    }
}
