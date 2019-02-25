/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 17:54
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
//

#include "assignment_3.h"

void init3(void);
void measureVoltage(void);
void displayTerminal(void);

char uartReceiveBuffer[20];
char converterBuffer[20];

void assignment3()
{
    init3();
    lcdWriteStringAt( 1,1, "Read voltage ADC0:");
    while (1)
    {
        //measureVoltage();
        displayTerminal();
    }
}

void init3()
{
    sei (); // Enable interrupts.
    adc255Init();
    initLCD();
    DDRA |= (1<<PIN1);
    initUARD0(9600, 0, 8, 0,1, 1 );

    DDRB = 0xff; // Configure all B ports as output.
    PORTB = 0xff; // Turn off all leds.
    _delay_ms(10);
}

void measureVoltage()
{
    double analogSignal;
    analogSignal = analogRead();
    sprintf(converterBuffer, "%.1f volt", (analogSignal*0.01960));
    lcdWriteStringAt(1,2, converterBuffer );

    PORTB = (uint8_t) (0xFF << (uint8_t)(analogSignal/25));
}
volatile unsigned char receive;
ISR(USART_RXC_vect)
{
    receive = UDR0;

    PORTA ^= (1 << PINA1);
}

void displayTerminal(void)
{
    receiveUART0();
    //sprintf(converterBuffer, "%s", (char *)receiveUART0());
    //lcdWriteStringAt(1,4, receiveUART0() );
}