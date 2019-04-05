/*
 * IS62WV12816BLL.h
 *
 *  Created on: 01 apr 2019
 *      Author: Alessio
 */

// " M bit SRAM by ISSI

#ifndef IS62WV12816BLL_H_
#define IS62WV12816BLL_H_

#include <MKL27Z64.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

void IS62WV12816BLL_init();
void IS62WV12816BLL_write(uint16_t dataIn, uint16_t address);
uint16_t IS62WV12816BLL_read(uint16_t address);

#endif /* IS62WV12816BLL_H_ */
