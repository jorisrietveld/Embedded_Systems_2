/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 17:53
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
//

#include "assignment_1.h"
char integerConv[20];
void assignment1()
{
    sei (); // Enable interrupts.
    adc255Init();
    initLCD();
    int analogSignal;
    while (1)
    {
        lcdWriteStringAt( 1,1, "Hello mouse");
        lcdWriteStringAt( 1,2, "Hello world");
        // y=80 _ cur[ 3-1 ] + (1-1)
        analogSignal = analogRead()/25;
        itoa( analogSignal, integerConv, 10 );
        lcdWriteFixedWidthStringAt( 1,4, integerConv,2);
        // y = 0x80 + cur[ 4-1] + (5-1)
        //lcdWriteStringAt( 1,1, "Hello world");
        //analog512Read();
    }
}