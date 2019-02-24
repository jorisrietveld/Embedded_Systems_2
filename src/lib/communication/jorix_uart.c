/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 22-022019 03:50
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */

#include "jorix_uart.h"

#define UART_PARITY_EVEN    0
#define UART_PARITY_ODD     1

// Used to store received data when interrupt mode is enabled.
volatile unsigned char receivedByte;

void
initUARD0(int baud, char asyncDoubleSpeed, char dataSize, char parity, char stopBits, char interruptEnable)
{
    // UBBR UARD Baud Rate = ( (clock speed) / 16 * braud ) -1
    uint16_t uartBaudRate = lrint((F_CPU/16*baud)-1);

    // Setup the baud speed mode, normal or double speed.
    if (asyncDoubleSpeed) {
        UCSR0A = (1 << U2X0); // double speed asynchronous.
    }
    else {
        UCSR0A &= ~(1 << U2X0);// Normal speed asynchronous.
    }

    // Setup the baud rate.
    UBRR0H = (unsigned char) (uartBaudRate >> 8); // Grab the high part of the baud rate.
    UBRR0L = (unsigned char) (uartBaudRate);  // And setup the least significant bits to the low reg.

    // Enable the UART transmit and receive pins.
    UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Enable receiver and transmitter.

    // Setup the receive mode, if true it fires a interrupt whenever data is received.
    if(interruptEnable){
        UCSR0B |= (1<<RXCIE0);
    }
    // Set the amount of stop bits after each message.
    if(stopBits == 2){
        UCSR0C = (1<<USBS0);
    }
    else{
        UCSR0C &= ~(1<<USBS0); // Set to 1 stop bit.
    }

    // Set the parity of the communication.
    if (parity==UART_PARITY_EVEN){
        UCSR0C |= (1 << UPM1);
        //UCSR0C &= ~(1 << UPM0);
    }
    else if(parity==UART_PARITY_ODD){
        UCSR0C |= (1 << UPM1) | (1 << UPM0);
    }

    // Set the size of the data packets.
    switch( dataSize ){
    case 6:
        UCSR0C |= (1<<UCSZ00);
        break;
    case 7:
        UCSR0C |= (2<<UCSZ00);
        break;
    case 8:
        UCSR0C |= (3<<UCSZ00);
        break;
    case 9:
        UCSR0C |= (7<<UCSZ00);
        break;
    default: // Set the default data length to 6 bits.
        UCSR0C |= (1<<UCSZ00);
        break;
    }
}

unsigned char receiveUART0()
{
    while (!(UCSR0A & ( 1<<RXC0)));
    return UDR0;
}

ISR(USART0_RX_vect)
{
    receivedByte = UDR0;
    // PORTn ^= 1<<PINn
}

void transmitUART0(unsigned char data)
{
    while (!(UCSR0A & ( 1<<UDRE0)));
    UDR0 = data;
}