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

extern uint8_t task1Flag;
extern uint8_t task2Flag;
extern uint8_t task3Flag;
extern uint8_t task4Flag;

void delay(uint16_t mseconds);
void pit_init(void);


#endif /* TIME_H_ */
