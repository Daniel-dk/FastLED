#ifndef __INC_LED_SYSDEFS_ARM_SAM_H
#define __INC_LED_SYSDEFS_ARM_SAM_H


#define FASTLED_ARM


// Define the rgister types
#if defined(ARDUINO) // && ARDUINO < 150 **** daniel
typedef volatile       uint32_t RoReg; /**< Read only 8-bit register (volatile const unsigned int) */
typedef volatile       uint32_t RwReg; /**< Read-Write 8-bit register (volatile unsigned int) */
#endif


// Setup DUE timer defines/channels/etc...
#ifndef DUE_TIMER_CHANNEL
#define DUE_TIMER_GROUP 0
#endif


#ifndef DUE_TIMER_CHANNEL
#define DUE_TIMER_CHANNEL 0
#endif




#if defined(__SAM3X8E__)

#define DUE_TIMER ((DUE_TIMER_GROUP==0) ? TC0 : ((DUE_TIMER_GROUP==1) ? TC1 : TC2))
#define DUE_TIMER_ID (ID_TC0 + (DUE_TIMER_GROUP*3) + DUE_TIMER_CHANNEL)
#define DUE_TIMER_VAL (DUE_TIMER->TC_CHANNEL[DUE_TIMER_CHANNEL].TC_CV << 1) 
#define DUE_TIMER_RUNNING ((DUE_TIMER->TC_CHANNEL[DUE_TIMER_CHANNEL].TC_SR & TC_SR_CLKSTA) != 0)

#elif defined(__SAM4S4A__)

#define DUE_TIMER TC0  // SAM4S has only TC0 available, no defs for TC1 or TC2
#define DUE_TIMER_ID ID_TC0
#define DUE_TIMER_VAL (DUE_TIMER->TC_CHANNEL[DUE_TIMER_CHANNEL].TC_CV<<1)
#define DUE_TIMER_RUNNING ((DUE_TIMER->TC_CHANNEL[DUE_TIMER_CHANNEL].TC_SR & TC_SR_CLKSTA) != 0)

#endif
#ifndef INTERRUPT_THRESHOLD
#define INTERRUPT_THRESHOLD 1
#endif

// Default to allowing interrupts
#ifndef FASTLED_ALLOW_INTERRUPTS
#define FASTLED_ALLOW_INTERRUPTS 1
#endif

#if FASTLED_ALLOW_INTERRUPTS == 1
#define FASTLED_ACCURATE_CLOCK
#endif

// reusing/abusing cli/sei defs for due
#define cli()  __disable_irq(); __disable_fault_irq();
#define sei() __enable_irq(); __enable_fault_irq();


#endif
