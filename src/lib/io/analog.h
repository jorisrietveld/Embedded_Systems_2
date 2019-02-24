/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 18:01
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
//

#ifndef EMBEDDED2_ANALOG_H
#define EMBEDDED2_ANALOG_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

#if !defined(ANALOG_255) || !defined(ANALOG_1024)
#define ANALOG_255
#endif

#if defined (ANALOG_255)
#include "analog255.h"
#elif defined( ANALOG_1024)
#include "analog1024.h"
#endif

int analogRead();



#endif //EMBEDDED2_ANALOG_H
