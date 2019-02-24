/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 18:00
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
//

#include "analog255.h"

/**
 * Initiate the ADC.
 */
void adc255Init ()
{
    ADMUX = (0 << MUX0) | (0 << MUX1) | (0 << MUX2) | (0 << MUX3) | (0 << MUX4) | // Select pin 0 on the ADC (PortA 0)
            (1 << ADLAR)
            | // Set the result shifted to the left so getting a 8 bit value is easier by only looking at ADCH
                    (1 << REFS0) | (0 << REFS1); // Set to an external reference

    // ADC Control and Status Register A
    ADCSRA = (0 << ADPS0) | (0 << ADPS1) | (1 << ADPS2) | // Set the prescaler to a devision factor of 16
            (1 << ADIE) | // Enable interrupts
            (0 << ADIF) | // Clear the interrupt flag
            (0 << ADATE) | // Auto Trigger Enable
            (1 << ADSC) | // Set the bit to start the conversion.
            (1 << ADEN); // Enable the ADC
}

