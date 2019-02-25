/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 03:50
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */

#include "jorix_uart_single.h"

#define UART_PARITY_EVEN    0
#define UART_PARITY_ODD     1

// Used to store received data when interrupt mode is enabled.
volatile unsigned char receivedByte;

void
initUARD0(int baud, char asyncDoubleSpeed, char dataSize, char parity, char stopBits, char interruptEnable)
{
    sei();
    // UBBR UARD Baud Rate = ( (clock speed) / 16 * braud ) -1
    //uint16_t uartBaudRate = lrint((F_CPU/(16*baud))-1);

    // Setup the baud speed mode, normal or double speed.
    if (asyncDoubleSpeed) {
        UCSRA = (1 << U2X0); // double speed asynchronous.
    }
    else {
        UCSRA &= ~(1 << U2X0);// Normal speed asynchronous.
    }

    // Setup the baud rate. todo cleanup
  //  UBRR0H = (unsigned char) (uartBaudRate >> 8); // Grab the high part of the baud rate.
   // UBRR0L = (unsigned char) (uartBaudRate);  // And setup the least significant bits to the low reg.

    UBRRH = UBRRH_VALUE;
    UBRRL = UBRRL_VALUE;

    // Enable the UART transmit and receive pins.
   // UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Enable receiver and transmitter.
    UCSRB = (1 << RXEN0) | (1 << TXEN0); // Enable receiver and transmitter.

    // Setup the receive mode, if true it fires a interrupt whenever data is received.
    if(interruptEnable){
        UCSRB |= (1<<RXCIE);
    }
    // Set the amount of stop bits after each message.
    if(stopBits == 2){
        UCSRC = (1<<USBS);
    }
    else{
        UCSRC &= ~(1<<USBS); // Set to 1 stop bit.
    }

    // Set the parity of the communication.
    if (parity==UART_PARITY_EVEN){
        UCSRC |= (1 << UPM1);
        //UCSR0C &= ~(1 << UPM0);
    }
    else if(parity==UART_PARITY_ODD){
        UCSRC |= (1 << UPM1) | (1 << UPM0);
    }

    // Set the size of the data packets.
    switch( dataSize ){
    case 6:
        UCSRC |= (1<<UCSZ1);
        break;
    case 7:
        UCSRC |= (2<<UCSZ00);
        break;
    case 8:
        UCSRC |= (3<<UCSZ00);
        break;
    case 9:
        UCSRC |= (7<<UCSZ00);
        break;
    default: // Set the default data length to 6 bits.
        UCSRC |= (1<<UCSZ00);
        break;
    }

    DDRA |= (1<<PIN1);
}

unsigned char receiveUART0()
{
    while (!(UCSRA & ( 1<<RXC)));
    receivedByte = UDR;
    PORTA ^= (1 << PINA1);
    return receivedByte;
}

void transmitUART0(unsigned char data)
{
    while (!(UCSRA & ( 1<<UDRE)));
    UDR = data;
    PORTA ^= (1 << PINA1);
}