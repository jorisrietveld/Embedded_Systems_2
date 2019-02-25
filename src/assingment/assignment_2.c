/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 17:57
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
#include "assignment_2.h"

void init2(void);

void assignment2()
{
    char convertedMeasurement[20];
    double analogSignal;

    init2();
    lcdWriteStringAt( 1,1, "Read voltage ADC0:");
    while (1)
    {
        analogSignal = analogRead();
        sprintf(convertedMeasurement, "%.1f volt", (analogSignal*0.01960));
        lcdWriteStringAt(1,2, convertedMeasurement );

        PORTB = (uint8_t) (0xFF << (uint8_t)(analogSignal/25));
    }
}

void init2()
{
    sei (); // Enable interrupts.
    adc255Init();
    initLCD();

    DDRB = 0xff; // Configure all B ports as output.
    PORTB = 0xff; // Turn off all leds.
    _delay_ms(10);
}