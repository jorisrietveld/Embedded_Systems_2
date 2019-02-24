/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 24-022019 12:27
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */

#include "analog.h"

volatile int lastADCMeasurement = 0;

/**
 * This interrupt routine gets triggered on every finished ADC measurement
  */
ISR(ADC_vect)
{
    lastADCMeasurement = ADCH; // Get the 8 bit measurement and store it.
    ADCSRA |= (1 << ADSC); // Start a new measurement.
}

int
analogRead()
{
    return lastADCMeasurement;
}

