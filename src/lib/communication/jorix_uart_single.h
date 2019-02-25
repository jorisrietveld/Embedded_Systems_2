/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 03:50
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */

#ifndef EMBEDDED2_JORIX_UART_H
#define EMBEDDED2_JORIX_UART_H

#include "lib/io/jorix_atmega32.h"
#include <avr/io.h>
#include <avr/interrupt.h>  // Used for enabling interrupts on receive.
//#define F_CPU 11059200
#define BAUD 9600
#include <util/setbaud.h>

#include <math.h>           // Used to calculate the baud rate.

#define UBBR_VALUE 25

void initUARD0(int baud, char asyncDoubleSpeed, char dataSize, char parity, char stopBits, char interruptEnable);
unsigned char receiveUART0();
void transmitUART0(unsigned char data);

#endif //EMBEDDED2_JORIX_UART_H
