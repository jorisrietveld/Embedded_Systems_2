/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 17:53
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
#include <stdio.h>
#include "assignment_1.h"

void init(void);

void assignment1()
{
    char convertedMeasurement[20];
    double analogSignal;

    init();
    lcdWriteStringAt( 1,1, "Read voltage ADC0:");
    while (1)
    {
        analogSignal = analogRead();
        sprintf(convertedMeasurement, "%.1f volt", (analogSignal*0.01960));
        lcdWriteStringAt(1,2, convertedMeasurement );

        PORTB = (uint8_t) (0xFF << (uint8_t)(analogSignal/25));
    }
}

void init()
{
    sei (); // Enable interrupts.
    adc255Init();
    initLCD();

    DDRB = 0xff; // Configure all B ports as output.
    PORTB = 0xff; // Turn off all leds.
    _delay_ms(10);
}