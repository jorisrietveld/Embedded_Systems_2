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
#include <math.h>           // Used to calculate the baud rate.

#define UBBR_VALUE 25

#endif //EMBEDDED2_JORIX_UART_H
