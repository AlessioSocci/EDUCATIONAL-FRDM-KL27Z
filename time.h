/*
 * time.h
 *
 *  Created on: 02 apr 2019
 *      Author: Alessio
 */

#ifndef TIME_H_
#define TIME_H_


#include <MKL27Z64.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

extern uint32_t ticks;

extern uint32_t burstTime_task0;

extern uint8_t arrival_task0_flag;
extern uint8_t disable_task0_flag;


void delay(uint32_t mseconds);
void pit_init(void);

#endif /* TIME_H_ */
