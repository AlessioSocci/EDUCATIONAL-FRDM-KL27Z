/*
 * time.c
 *
 *  Created on: 02 apr 2019
 *      Author: Alessio
 */

#include "time.h"

uint32_t ticks = 0;

uint16_t arrival_task0_counter = 0;
uint16_t revival_task0_counter = 0;
uint32_t burstTime_task0 = 0;

// BARE METAL O.S. IS A FIFO STATIC - NON-PREEMPTIVE SCHEDULING

uint32_t currTicks = 0;

uint32_t arrival_task0_time = 1000; // threshold of counter in ms
uint32_t revival_task0_time = 1000;


uint8_t arrival_task0_flag = 0;
uint8_t disable_task0_flag = 0;


void task_scheduler(void)
{
	arrival_task0_counter++;
	if(arrival_task0_counter == arrival_task0_time)
	{
		arrival_task0_counter = 0;
		arrival_task0_flag = 1;
	}

	revival_task0_counter++;
	if(revival_task0_counter == revival_task0_time && disable_task0_flag == 1)
	{
		revival_task0_counter = 0;
		arrival_task0_counter = 0;
		disable_task0_flag = 0;
	}
	else if(revival_task0_counter == revival_task0_time && disable_task0_flag == 0)
	{
		revival_task0_counter = 0;
	}
}

void PIT_IRQHandler(void)
{
	ticks++;

	task_scheduler();

	PIT->CHANNEL->TFLG = (1 << 0); // Clear interrupt flag
}

void delay(uint32_t mseconds) // Delay function, based on pit
{
    uint32_t currTicks = ticks;

    while((ticks - currTicks) < mseconds);
}

void pit_init(void)
{
   PORTB->PCR[19] |= (1 << 8); // PORTB pin 19 in alt1 mode, green led

   GPIOB->PDDR |= (1 << 19); // PORTB pin 19 set as output

   GPIOB->PDOR |= (1 << 19); // PORTB pin 19 default low

   SIM->SCGC6 |= (1 << 23);  // enable clock for PIT

   PIT->MCR &= ~(1 << 1); // enable PIT module // Attention!! There are many error in reference manual regarding bit field.

   PIT->CHANNEL->LDVAL |= (CLOCK_GetBusClkFreq() / 1000) - 1; // set time period : desired timing * bus clock -1

   PIT->CHANNEL->TCTRL |= (1 << 1) | (1 << 0); // Timer interrupt enable, Timer enable

   NVIC->IP[5] |= (1 << 22); // preemptive priority 1, min value is 3, max and default is 0

   NVIC->ISER[0] |= (1 << 22);  // interrupt enable in NVIC
}
