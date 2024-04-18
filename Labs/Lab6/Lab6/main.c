#include"../../Utility/address_map_arm.h"
#include"interrupt.h"

void main(void)
{
    set_A9_IRQ_stack();

    enable_A9_interrupts();

    ConfigureGIC();

	/* setup the interval timer interrupts in the FPGA */

    volatile int* interval_timer_ptr = (int*)TIMER_BASE; // interal timer base address

    int counter = 100000000; // 1/(100 MHz) x 1x10^8 = 1 sec
    *(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
    *(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;

    /* start interval timer, enable its interrupts */
    *(interval_timer_ptr + 1) = 0x7; // STOP = 0, START = 1, CONT = 1, ITO = 1	

    while (1)
        ;

}


