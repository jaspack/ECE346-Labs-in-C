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

    int isGoingLeft = 1; // State of movement for the LEDs

    int currentState = rightBound;
    while (1)
    {
        // Check to see if the lights are currently moving to the left
        if (isGoingLeft) 
            // If there going left check to see if the left bound has been reached
            if (currentState != leftBound) 
                // If not, shift the current state to the left
                currentState = currentState << 1;
            else
            {
                // If it is, start going right
                isGoingLeft = 0; 
                // We have to update prior to exiting the if statement or the far left and right LEDs will remain illuminated for an additional cycle
                // This gives a different appearance to the pattern. You can try commenting out this line and the similar line in the 'going right' section to see the difference!
                currentState = currentState >> 1;
            }
        else // repeat the previous block but in reverse
            if (currentState != 1) // If they're going right check to see if the right bound has been reached
                // If not, shift the current state to the right
                currentState = currentState >> 1;
            else
            {
                // If it is, start going left
                isGoingLeft = 1;
                currentState = currentState << 1; // Comment out this line for the other pattern if desired
            }
        
        *(LED_ptr) = currentState; // update the LEDs to the current state
        for (int i = 0; i < DELAY; i++) {} // delay
    }
}
