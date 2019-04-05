/*
 * IS62WV12816BLL.c
 *
 *  Created on: 01 apr 2019
 *      Author: Alessio
 */


#include "IS62WV12816BLL.h"
#include "time.h"

void IS62WV12816BLL_init()
{
	PORTE->PCR[0] |= (1 << 8); // Alt 1 mode for GPIO // NWE - Write Enable
	PORTE->PCR[0] &= ~(1 << 2); // Fast Slew
	GPIOE->PDDR |= (1 << 0); // Initially set as output

    PORTE->PCR[1] |= (1 << 8); // NOE - Output Enable
    PORTE->PCR[1] &= ~(1 << 2); // Fast Slew
    GPIOE->PDDR |= (1 << 1);

    PORTC->PCR[1] |= (1 << 8); // NBL0 - Lower Byte Control
    PORTC->PCR[1] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 1);

//    PORTC->PCR[2] |= (1 << 8); // NBL1 - Upper Byte Control
//    PORTC->PCR[1] &= ~(1 << 2); // Fast Slew
//    GPIOC->PDDR |= (1 << 2);

    PORTC->PCR[5] |= (1 << 8); // CS1 - Chip Enable 1
    PORTC->PCR[5] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 5);


    PORTC->PCR[3] |= (1 << 8); // D15
    PORTC->PCR[3] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 3);

    PORTE->PCR[16] |= (1 << 8); // D14
    PORTE->PCR[16] &= ~(1 << 2); // Fast Slew
    GPIOE->PDDR |= (1 << 16);

    PORTB->PCR[19] |= (1 << 8); // D13
    PORTB->PCR[19] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 19);

    PORTC->PCR[0] |= (1 << 8); // D12
    PORTC->PCR[0] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 0);

    PORTB->PCR[18] |= (1 << 8); // D11
    PORTB->PCR[18] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 18);

    PORTE->PCR[20] |= (1 << 8); // D10
    PORTE->PCR[20] &= ~(1 << 2); // Fast Slew
    GPIOE->PDDR |= (1 << 20);

    PORTB->PCR[17] |= (1 << 8); // D9
    PORTB->PCR[17] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 17);

    PORTE->PCR[21] |= (1 << 8); // D8
    PORTE->PCR[21] &= ~(1 << 2); // Fast Slew
    GPIOE->PDDR |= (1 << 21);

    PORTB->PCR[16] |= (1 << 8); // D7
    PORTB->PCR[16] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 16);

    PORTB->PCR[1] |= (1 << 8); // D6
    PORTB->PCR[1] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 1);

    PORTC->PCR[6] |= (1 << 8); // D5
    PORTC->PCR[6] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 6);

    PORTB->PCR[0] |= (1 << 8); // D4
    PORTB->PCR[0] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 0);

    PORTC->PCR[11] |= (1 << 8); // D3
    PORTC->PCR[11] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 11);

    PORTD->PCR[7] |= (1 << 8); // D2
    PORTD->PCR[7] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 7);

    PORTC->PCR[10] |= (1 << 8); // D1
    PORTC->PCR[10] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 10);

    PORTD->PCR[6] |= (1 << 8); // D0
    PORTD->PCR[6] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 6);


    PORTA->PCR[12] |= (1 << 8); // A16
    PORTA->PCR[2] &= ~(1 << 2); // Fast Slew
    GPIOA->PDDR |= (1 << 12);

    PORTD->PCR[0] |= (1 << 8); // A15
    PORTD->PCR[0] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 0);

    PORTE->PCR[25] |= (1 << 8); // A14
    PORTE->PCR[25] &= ~(1 << 2); // Fast Slew
    GPIOE->PDDR |= (1 << 25);

    PORTD->PCR[1] |= (1 << 8); // A13
    PORTD->PCR[1] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 1);

    PORTA->PCR[13] |= (1 << 8); // A12
    PORTA->PCR[13] &= ~(1 << 2); // Fast Slew
    GPIOA->PDDR |= (1 << 13);

    PORTD->PCR[2] |= (1 << 8); // A11
    PORTD->PCR[2] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 2);

    PORTE->PCR[24] |= (1 << 8); // A10
    PORTE->PCR[24] &= ~(1 << 2); // Fast Slew
    GPIOE->PDDR |= (1 << 24);

    PORTD->PCR[3] |= (1 << 8); // A9
    PORTD->PCR[3] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 3);

    PORTC->PCR[9] |= (1 << 8); // A8
    PORTC->PCR[9] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 9);

    PORTD->PCR[4] |= (1 << 8); // A7
    PORTD->PCR[4] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 4);

    PORTC->PCR[8] |= (1 << 8); // A6
    PORTC->PCR[8] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 8);

    PORTD->PCR[5] |= (1 << 8); // A5
    PORTD->PCR[5] &= ~(1 << 2); // Fast Slew
    GPIOD->PDDR |= (1 << 5);

    PORTE->PCR[31] |= (1 << 8); // A4
    PORTE->PCR[31] &= ~(1 << 2); // Fast Slew
    GPIOE->PDDR |= (1 << 31);

    PORTB->PCR[3] |= (1 << 8); // A3
    PORTB->PCR[3] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 3);

    PORTA->PCR[5] |= (1 << 8); // A2
    PORTA->PCR[5] &= ~(1 << 2); // Fast Slew
    GPIOA->PDDR |= (1 << 5);

    PORTB->PCR[2] |= (1 << 8); // A1
    PORTB->PCR[2] &= ~(1 << 2); // Fast Slew
    GPIOB->PDDR |= (1 << 2);

    PORTC->PCR[4] |= (1 << 8); // A0
    PORTC->PCR[4] &= ~(1 << 2); // Fast Slew
    GPIOC->PDDR |= (1 << 4);
}

void IS62WV12816BLL_write(uint16_t dataIn, uint16_t address)
{
	GPIOE->PDDR |= (1 << 16); // D15 		// GPIO direction set as output...
	GPIOC->PDDR |= (1 << 3); // D14
	GPIOB->PDDR |= (1 << 19); // D13
	GPIOC->PDDR |= (1 << 0); // D12
	GPIOB->PDDR |= (1 << 18); // D11
	GPIOE->PDDR |= (1 << 20); // D10
	GPIOB->PDDR |= (1 << 17); // D9
	GPIOE->PDDR |= (1 << 21); // D8
	GPIOB->PDDR |= (1 << 16); // D7
	GPIOB->PDDR |= (1 << 1); // D6
	GPIOC->PDDR |= (1 << 6); // D5
	GPIOB->PDDR |= (1 << 0); // D4
	GPIOC->PDDR |= (1 << 11); // D3
	GPIOD->PDDR |= (1 << 7); // D2
	GPIOC->PDDR |= (1 << 10); // D1
	GPIOD->PDDR |= (1 << 6); // D0

	GPIOC->PSOR |= (1 << 5); // CS1 High

	delay(5);

	GPIOE->PSOR |= (1 << 0); // NWE High

	delay(5);

	GPIOC->PSOR |= (1 << 1); // NBL01 High

	delay(5);

	GPIOE->PSOR |= (1 << 1); // NOE High

	delay(5);

	((address & 0x8001) == 0x8001) ? (GPIOA->PSOR |= (1 << 12)) : (GPIOA->PCOR |= (1 << 12)); // A16
	((address & 0x8000) == 0x8000) ? (GPIOD->PSOR |= (1 << 0)) : (GPIOD->PCOR |= (1 << 0)); // A15
	((address & 0x4000) == 0x4000) ? (GPIOE->PSOR |= (1 << 25)) : (GPIOE->PCOR |= (1 << 25)); // A14
	((address & 0x2000) == 0x2000) ? (GPIOD->PSOR |= (1 << 1)) : (GPIOD->PCOR |= (1 << 1)); // A13
	((address & 0x1000) == 0x1000) ? (GPIOA->PSOR |= (1 << 13)) : (GPIOA->PCOR |= (1 << 13)); // A12
	((address & 0x800) == 0x800) ? (GPIOD->PSOR |= (1 << 2)) : (GPIOD->PCOR |= (1 << 2)); // A11
	((address & 0x400) == 0x400) ? (GPIOE->PSOR |= (1 << 24)) : (GPIOE->PCOR |= (1 << 24)); // A10
	((address & 0x200) == 0x200) ? (GPIOD->PSOR |= (1 << 3)) : (GPIOD->PCOR |= (1 << 3)); // A9
	((address & 0x100) == 0x100) ? (GPIOC->PSOR |= (1 << 9)) : (GPIOC->PCOR |= (1 << 9)); // A8
	((address & 0x80) == 0x80) ? (GPIOD->PSOR |= (1 << 4)) : (GPIOD->PCOR |= (1 << 4)); // A7
	((address & 0x40) == 0x40) ? (GPIOC->PSOR |= (1 << 8)) : (GPIOC->PCOR |= (1 << 8)); // A6
	((address & 0x20) == 0x20) ? (GPIOD->PSOR |= (1 << 5)) : (GPIOD->PCOR |= (1 << 5)); // A5
	((address & 0x10) == 0x10) ? (GPIOE->PSOR |= (1 << 31)) : (GPIOE->PCOR |= (1 << 31)); // A4
	((address & 0x8) == 0x8) ? (GPIOB->PSOR |= (1 << 3)) : (GPIOB->PCOR |= (1 << 3)); // A3
	((address & 0x4) == 0x4) ? (GPIOA->PSOR |= (1 << 5)) : (GPIOA->PCOR |= (1 << 5)); // A2
	((address & 0x2) == 0x2) ? (GPIOB->PSOR |= (1 << 2)) : (GPIOB->PCOR |= (1 << 2)); // A1
	((address & 0x1) == 0x1) ? (GPIOC->PSOR |= (1 << 4)) : (GPIOC->PCOR |= (1 << 4)); // A0

	delay(5);

	((dataIn & 0x8000) == 0x8000) ? (GPIOC->PSOR |= (1 << 3)) : (GPIOC->PCOR |= (1 << 3)); // D15
	((dataIn & 0x4000) == 0x4000) ? (GPIOE->PSOR |= (1 << 16)) : (GPIOE->PCOR |= (1 << 16)); // D14
	((dataIn & 0x2000) == 0x2000) ? (GPIOB->PSOR |= (1 << 19)) : (GPIOB->PCOR |= (1 << 19)); // D13
	((dataIn & 0x1000) == 0x1000) ? (GPIOC->PSOR |= (1 << 0)) : (GPIOC->PCOR |= (1 << 0)); // D12
	((dataIn & 0x800) == 0x800) ? (GPIOB->PSOR |= (1 << 18)) : (GPIOB->PCOR |= (1 << 18)); // D11
	((dataIn & 0x400) == 0x400) ? (GPIOE->PSOR |= (1 << 20)) : (GPIOE->PCOR |= (1 << 20)); // D10
	((dataIn & 0x200) == 0x200) ? (GPIOB->PSOR |= (1 << 17)) : (GPIOB->PCOR |= (1 << 17)); // D9
	((dataIn & 0x100) == 0x100) ? (GPIOE->PSOR |= (1 << 21)) : (GPIOE->PCOR |= (1 << 21)); // D8
	((dataIn & 0x80) == 0x80) ? (GPIOB->PSOR |= (1 << 16)) : (GPIOB->PCOR |= (1 << 16)); // D7
	((dataIn & 0x40) == 0x40) ? (GPIOB->PSOR |= (1 << 1)) : (GPIOB->PCOR |= (1 << 1)); // D6
	((dataIn & 0x20) == 0x20) ? (GPIOC->PSOR |= (1 << 6)) : (GPIOC->PCOR |= (1 << 6)); // D5
	((dataIn & 0x10) == 0x10) ? (GPIOB->PSOR |= (1 << 0)) : (GPIOB->PCOR |= (1 << 0)); // D4
	((dataIn & 0x8) == 0x8) ? (GPIOC->PSOR |= (1 << 11)) : (GPIOC->PCOR |= (1 << 11)); // D3
	((dataIn & 0x4) == 0x4) ? (GPIOD->PSOR |= (1 << 7)) : (GPIOD->PCOR |= (1 << 7)); // D2
	((dataIn & 0x2) == 0x2) ? (GPIOC->PSOR |= (1 << 10)) : (GPIOC->PCOR |= (1 << 10)); // D1
	((dataIn & 0x1) == 0x1) ? (GPIOD->PSOR |= (1 << 6)) : (GPIOD->PCOR |= (1 << 6)); // D0

	delay(5);

	GPIOC->PCOR |= (1 << 5); // CS1 Low

	delay(5);

	GPIOC->PCOR |= (1 << 1); // NBL0-1 Low

	delay(5);

	GPIOE->PCOR |= (1 << 0); // NWE Low

	delay(5);

	GPIOC->PSOR |= (1 << 5); // CS1 High

	delay(5);

	GPIOC->PCOR |= (1 << 3); // D15
	GPIOE->PCOR |= (1 << 16); // D14
	GPIOB->PCOR |= (1 << 19); // D13
	GPIOC->PCOR |= (1 << 0); // D12
	GPIOB->PCOR |= (1 << 18); // D11
	GPIOE->PCOR |= (1 << 20); // D10
	GPIOB->PCOR |= (1 << 17); // D9
	GPIOE->PCOR |= (1 << 21); // D8
	GPIOB->PCOR |= (1 << 16); // D7
	GPIOB->PCOR |= (1 << 1); // D6
	GPIOC->PCOR |= (1 << 6); // D5
	GPIOB->PCOR |= (1 << 0); // D4
	GPIOC->PCOR |= (1 << 11); // D3
	GPIOD->PCOR |= (1 << 7); // D2
	GPIOC->PCOR |= (1 << 10); // D1
	GPIOD->PCOR |= (1 << 6); // D0
}


//C3(accelerometer remove J27 and J28) B19(led, remove R80) B18(led, remove R78) D7(magnetometer or accelerometer I2C SCL, remove J24) D6(magnetometer or accelerometer I2C SDA remove J24)

uint16_t IS62WV12816BLL_read(uint16_t address)
{
	uint16_t dataOut = 0;

	GPIOE->PDDR &= ~(1 << 16); // D15 		// GPIO direction set as input...
	PORTE->PCR[16] &= ~(1 << 0); // Pull Down
//	PORTE->PCR[16] |= (1 << 0); // Pull Up
	PORTE->PCR[16] |= (1 << 1); // Pull Enable
	delay(5);
//	PORTE->PCR[16] &= ~(1 << 1); // Pull Disable

	GPIOC->PDDR &= ~(1 << 3); // D14
	PORTC->PCR[3] &= ~(1 << 0); // Pull Down
//	PORTC->PCR[3] |= (1 << 0); // Pull Up
	PORTC->PCR[3] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTC->PCR[3] &= ~(1 << 1); // Pull Disable

	GPIOB->PDDR &= ~(1 << 19); // D13
	PORTB->PCR[19] &= ~(1 << 0); // Pull Down
//	PORTB->PCR[19] |= (1 << 0); // Pull Up
	PORTB->PCR[19] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTB->PCR[19] &= ~(1 << 1); // Pull Disable

	GPIOC->PDDR &= ~(1 << 0); // D12
	PORTC->PCR[0] &= ~(1 << 0); // Pull Down
//	PORTC->PCR[0] |= (1 << 0); // Pull Up
	PORTC->PCR[0] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTC->PCR[0] &= ~(1 << 1); // Pull Disable

	GPIOB->PDDR &= ~(1 << 18); // D11
	PORTB->PCR[18] &= ~(1 << 0); // Pull Down
//	PORTB->PCR[18] |= (1 << 0); // Pull Up
	PORTB->PCR[18] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTB->PCR[18] &= ~(1 << 1); // Pull Disable

	GPIOE->PDDR &= ~(1 << 20); // D10
	PORTE->PCR[20] &= ~(1 << 0); // Pull Down
//	PORTE->PCR[20] |= (1 << 0); // Pull Up
	PORTE->PCR[20] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTE->PCR[20] &= ~(1 << 1); // Pull Disable

	GPIOB->PDDR &= ~(1 << 17); // D9
	PORTB->PCR[17] &= ~(1 << 0); // Pull Down
//	PORTB->PCR[17] |= (1 << 0); // Pull Up
	PORTB->PCR[17] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTB->PCR[17] &= ~(1 << 1); // Pull Disable

	GPIOE->PDDR &= ~(1 << 21); // D8
	PORTE->PCR[21] &= ~(1 << 0); // Pull Down
//	PORTE->PCR[21] |= (1 << 0); // Pull Up
	PORTE->PCR[21] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTE->PCR[21] &= ~(1 << 1); // Pull Disable

	GPIOB->PDDR &= ~(1 << 16); // D7
	PORTB->PCR[16] &= ~(1 << 0); // Pull Down
//	PORTB->PCR[16] |= (1 << 0); // Pull Up
	PORTB->PCR[16] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTB->PCR[16] &= ~(1 << 1); // Pull Disable

	GPIOB->PDDR &= ~(1 << 1); // D6
	PORTB->PCR[1] &= ~(1 << 0); // Pull Down
//	PORTB->PCR[1] |= (1 << 0); // Pull Up
	PORTB->PCR[1] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTB->PCR[1] &= ~(1 << 1); // Pull Disable

	GPIOC->PDDR &= ~(1 << 6); // D5
	PORTC->PCR[6] &= ~(1 << 0); // Pull Down
//	PORTC->PCR[6] |= (1 << 0); // Pull Up
	PORTC->PCR[6] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTC->PCR[6] &= ~(1 << 1); // Pull Disable

	GPIOB->PDDR &= ~(1 << 0); // D4
	PORTB->PCR[0] &= ~(1 << 0); // Pull Down
//	PORTB->PCR[0] |= (1 << 0); // Pull Up
	PORTB->PCR[0] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTB->PCR[0] &= ~(1 << 1); // Pull Disable

	GPIOC->PDDR &= ~(1 << 11); // D3
	PORTC->PCR[11] &= ~(1 << 0); // Pull Down
//	PORTC->PCR[11] |= (1 << 0); // Pull Up
	PORTC->PCR[11] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTC->PCR[11] &= ~(1 << 1); // Pull Disable

	GPIOD->PDDR &= ~(1 << 7); // D2
	PORTD->PCR[7] &= ~(1 << 0); // Pull Down
//	PORTD->PCR[7] |= (1 << 0); // Pull Up
	PORTD->PCR[7] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTD->PCR[7] &= ~(1 << 1); // Pull Disable

	GPIOC->PDDR &= ~(1 << 10); // D1
	PORTC->PCR[10] &= ~(1 << 0); // Pull Down
//	PORTC->PCR[10] |= (1 << 0); // Pull Up
	PORTC->PCR[10] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTC->PCR[10] &= ~(1 << 1); // Pull Disable

	GPIOD->PDDR &= ~(1 << 6); // D0
	PORTD->PCR[6] &= ~(1 << 0); // Set Pull Down
//	PORTD->PCR[6] |= (1 << 0); // Set Pull Up
	PORTD->PCR[6] |= (1 << 1); // Pull Enable
	delay(5);
	//	PORTD->PCR[6] &= ~(1 << 1); // Pull Disable

	delay(10);

	GPIOC->PSOR |= (1 << 5); // CS1 High

	delay(5);

	GPIOC->PSOR |= (1 << 1); // NBL01 High

	delay(5);

	GPIOE->PSOR |= (1 << 0); // NWE High

	delay(5);

	GPIOE->PSOR |= (1 << 1); // NOE High

	delay(5);

	((address & 0x8001) == 0x8001) ? (GPIOA->PSOR |= (1 << 12)) : (GPIOA->PCOR |= (1 << 12)); // A16
	((address & 0x8000) == 0x8000) ? (GPIOD->PSOR |= (1 << 0)) : (GPIOD->PCOR |= (1 << 0)); // A15
	((address & 0x4000) == 0x4000) ? (GPIOE->PSOR |= (1 << 25)) : (GPIOE->PCOR |= (1 << 25)); // A14
	((address & 0x2000) == 0x2000) ? (GPIOD->PSOR |= (1 << 1)) : (GPIOD->PCOR |= (1 << 1)); // A13
	((address & 0x1000) == 0x1000) ? (GPIOA->PSOR |= (1 << 13)) : (GPIOA->PCOR |= (1 << 13)); // A12
	((address & 0x800) == 0x800) ? (GPIOD->PSOR |= (1 << 2)) : (GPIOD->PCOR |= (1 << 2)); // A11
	((address & 0x400) == 0x400) ? (GPIOE->PSOR |= (1 << 24)) : (GPIOE->PCOR |= (1 << 24)); // A10
	((address & 0x200) == 0x200) ? (GPIOD->PSOR |= (1 << 3)) : (GPIOD->PCOR |= (1 << 3)); // A9
	((address & 0x100) == 0x100) ? (GPIOC->PSOR |= (1 << 9)) : (GPIOC->PCOR |= (1 << 9)); // A8
	((address & 0x80) == 0x80) ? (GPIOD->PSOR |= (1 << 4)) : (GPIOD->PCOR |= (1 << 4)); // A7
	((address & 0x40) == 0x40) ? (GPIOC->PSOR |= (1 << 8)) : (GPIOC->PCOR |= (1 << 8)); // A6
	((address & 0x20) == 0x20) ? (GPIOD->PSOR |= (1 << 5)) : (GPIOD->PCOR |= (1 << 5)); // A5
	((address & 0x10) == 0x10) ? (GPIOE->PSOR |= (1 << 31)) : (GPIOE->PCOR |= (1 << 31)); // A4
	((address & 0x8) == 0x8) ? (GPIOB->PSOR |= (1 << 3)) : (GPIOB->PCOR |= (1 << 3)); // A3
	((address & 0x4) == 0x4) ? (GPIOA->PSOR |= (1 << 5)) : (GPIOA->PCOR |= (1 << 5)); // A2
	((address & 0x2) == 0x2) ? (GPIOB->PSOR |= (1 << 2)) : (GPIOB->PCOR |= (1 << 2)); // A1
	((address & 0x1) == 0x1) ? (GPIOC->PSOR |= (1 << 4)) : (GPIOC->PCOR |= (1 << 4)); // A0

	delay(5);

	GPIOC->PCOR |= (1 << 5); // CS1 Low

	delay(5);

	GPIOC->PCOR |= (1 << 1); // NBL0-1 Low

	delay(5);

	GPIOE->PCOR |= (1 << 1); // NOE Low

	delay(5);

	((GPIOC->PDIR & (1 << 3)) == (1 << 3)) ? (dataOut |= 0x8000) : dataOut; // D15
	((GPIOE->PDIR & (1 << 16)) == (1 << 16)) ? (dataOut |= 0x4000) : dataOut; // D14
	((GPIOB->PDIR & (1 << 19)) == (1 << 19)) ? (dataOut |= 0x2000) : dataOut; // D13
	((GPIOC->PDIR & (1 << 0)) == (1 << 0)) ? (dataOut |= 0x1000) : dataOut; // D12
	((GPIOB->PDIR & (1 << 18)) == (1 << 18)) ? (dataOut |= 0x800) : dataOut; // D11
	((GPIOE->PDIR & (1 << 20)) == (1 << 20)) ? (dataOut |= 0x400) : dataOut; // D10
	((GPIOB->PDIR & (1 << 17)) == (1 << 17)) ? (dataOut |= 0x200) : dataOut; // D9
	((GPIOE->PDIR & (1 << 21)) == (1 << 21)) ? (dataOut |= 0x100) : dataOut; // D8
	((GPIOB->PDIR & (1 << 16)) == (1 << 16)) ? (dataOut |= 0x80) : dataOut; // D7
	((GPIOB->PDIR & (1 << 1)) == (1 << 1)) ? (dataOut |= 0x40) : dataOut; // D6
	((GPIOC->PDIR & (1 << 6)) == (1 << 6)) ? (dataOut |= 0x20) : dataOut; // D5
	((GPIOB->PDIR & (1 << 0)) == (1 << 0)) ? (dataOut |= 0x10) : dataOut; // D4
	((GPIOC->PDIR & (1 << 11)) == (1 << 11)) ? (dataOut |= 0x8) : dataOut; // D3
	((GPIOD->PDIR & (1 << 7)) == (1 << 7)) ? (dataOut |= 0x4) : dataOut; // D2
	((GPIOC->PDIR & (1 << 10)) == (1 << 10)) ? (dataOut |= 0x2) : dataOut; // D1
	((GPIOD->PDIR & (1 << 6)) == (1 << 6)) ? (dataOut |= 0x1) : dataOut; // D0

	delay(5);

	GPIOC->PSOR |= (1 << 5); // CS1 High

	delay(5);

	GPIOC->PSOR |= (1 << 1); // NBL0-1 High

	delay(5);

	GPIOE->PSOR |= (1 << 1); // NOE High

	return dataOut;
}

void IS62WV12816BLL_outputDisable(void)
{
	GPIOE->PSOR |= (1 << 0); // NWE High
	GPIOC->PCOR |= (1 << 5); // CS1 Low
	GPIOE->PSOR |= (1 << 1); // NOE High
}

void IS62WV12816BLL_deselect(void)
{
	GPIOC->PSOR |= (1 << 5); // CS1 High
}
