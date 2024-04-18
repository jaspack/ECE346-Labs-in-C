#include"../../Utility/address_map_arm.h"
#include"interval_timer_ISR.h"
#include"interrupt_ID.h"
#include"defines.h"

void __attribute__((interrupt)) __cs3_isr_irq(void)
{
    // Read the ICCIAR from the processor interface
    int address = MPCORE_GIC_CPUIF + ICCIAR;
    int int_ID = *((int*)address);
    
    if (int_ID == HPS_TIMER0_IRQ) // check if interrupt is from the HPS timer
        ;   // Not used so skip
    else if (int_ID == INTERVAL_TIMER_IRQ) // check if interrupt is from the Altera timer
        interval_timer_ISR();
    else if (int_ID == KEYS_IRQ) // check if interrupt is from the KEYs
        ;   // Not used so skip
    else
        while (1)
            ; // if unexpected, then stay here

    // Write to the End of Interrupt Register (ICCEOIR)
    address = MPCORE_GIC_CPUIF + ICCEOIR;
    *((int*)address) = int_ID;

    return;
}

// Define the remaining exception handlers
void __attribute__((interrupt)) __cs3_reset(void)
{while (1);}

void __attribute__((interrupt)) __cs3_isr_undef(void)
{while (1);}

void __attribute__((interrupt)) __cs3_isr_swi(void)
{while (1);}

void __attribute__((interrupt)) __cs3_isr_pabort(void)
{while (1);}

void __attribute__((interrupt)) __cs3_isr_dabort(void)
{while (1);}

void __attribute__((interrupt)) __cs3_isr_fiq(void)
{while (1);}

// Initialize the banked stack pointer register for IRQ mode
void set_A9_IRQ_stack(void)
{
    int stack, mode;
    // top of A9 onchip memory, aligned to 8 bytes
    stack = A9_ONCHIP_END - 7; 
    // change processor to IRQ mode with interrupts disabled 
    mode = INT_DISABLE | IRQ_MODE;
    asm("msr cpsr, %[ps]" : : [ps] "r"(mode));
    // set banked stack pointer
    asm("mov sp, %[ps]" : : [ps] "r"(stack));

    // go back to SVC mode before executing subroutine return!
    mode = INT_DISABLE | SVC_MODE;
    asm("msr cpsr, %[ps]" : : [ps] "r"(mode));
}


// Turn on interrupts in the ARM processor
void enable_A9_interrupts(void)
{
    int status = SVC_MODE | INT_ENABLE;
    asm("msr cpsr, %[ps]" : : [ps] "r"(status));
}


// Configure the Generic Interrupt Controller (GIC)
void ConfigureGIC(void)
{
    // Configure the FPGA IRQ0(interval timer)
    *((int*)0xFFFED848) = 0x00000001;
    *((int*)0xFFFED108) = 0x00000100;

    // Set Interrupt Priority Mask Register (ICCPMR). Enable interrupts of all priorities
    *((int*)(MPCORE_GIC_CPUIF + ICCPMR)) = 0xFFFF;

    // Set CPU Interface Control Register (ICCICR). Enable signaling of interrupts
    *((int*)(MPCORE_GIC_CPUIF + ICCICR)) = 0x1;

    // Configure the Distributor Control Register (ICDDCR) to send pending interrupts to CPUs
    *((int*)(MPCORE_GIC_DIST + ICDDCR)) = 0x1;

}