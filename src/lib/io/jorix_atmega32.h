/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 23-022019 14:06
 * Licence: GPLv3 - General Public Licence version 3 
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
//

#ifndef EMBEDDED2_JORIX_ATMEGA32_H
#define EMBEDDED2_JORIX_ATMEGA32_H
/**
 * Author: Joris Rietveld <jorisrietveld@gmail.com>
 * Created: 23-022019 14:06
 * Licence: GPLv3 - General Public Licence version 3
 * Licence url: <https://www.gnu.org/licenses/gpl-3.0.txt>
 */
//Register names
#define OCR0A   OCR0
#define EIMSK   GICR
#define EIFR    GIFR
#define TIMSK0  TIMSK
#define TIMSK1  TIMSK
#define TIMSK2  TIMSK
#define TIFR0   TIFR
#define TIFR1   TIFR
#define TIFR2   TIFR
#define SPMCSR  SPMCR
#define SMCR    MCUCR
#define EICRA   MCUCR
#define MCUSR   MCUCSR
#define TCCR0A  TCCR0
#define ADCSRB  SFIOR
#define TCCR2A  TCCR2
#define OCR2A   OCR2
#define WDTCSR  WDTCR
#define UBRR0H  UBRRH
#define UCSR0C  UCSRC
#define UDR0    UDR
#define UCSR0A  UCSRA
#define UCSR0B  UCSRB
#define UBRR0L  UBRRL

//Bit names
#define OCIE2A  OCIE2
#define ICIE1   TICIE1
#define OCIE0A  OCIE0
#define OCF2A   OCF2
#define OCF0A   OCF0
#define ISC20   ISC2
#define FOC0A   FOC0
#define COM0A1  COM01
#define COM0A0  COM00
#define PSRASY  PSR2
#define PSRSYNC PSR10
#define FOC2A   FOC2
#define COM2A1  COM21
#define COM2A0  COM20
#define OCR2AUB OCR2UB
#define TCR2AUB TCR2UB
#define UMSEL00 UMSEL
#define UPM10   UPM1
#define UPM00   UPM0
#define USBS0   USBS
#define UCSZ00  UCSZ1
#define UCSZ10  UCSZ2
#define UCPOL0  UCPOL
#define RXC0    RXC
#define TXC0    TXC
#define UDRE0   UDRE
#define FE0     FE
#define DOR0    DOR
#define UPE0    PE
#define U2X0    U2X
#define MPCM0   MPCM
#define RXCIE0  RXCIE
#define TXCIE0  TXCIE
#define UDRIE0  UDRIE
#define RXEN0   RXEN
#define TXEN0   TXEN
#define UCSZ02  UCSZ2
#define RXB80   RXB8
#define TXB80   TXB8

//Interrupt vectors
#define TIMER2_COMPA_vect     TIMER2_COMP_vect
#define TIMER2_COMPA_vect_num TIMER2_COMP_vect_num
#define TIMER0_COMPA_vect     TIMER0_COMP_vect
#define TIMER0_COMPA_vect_num TIMER0_COMP_vect_num
#define USART0_RX_vect        USART_RXC_vect
#define USART0_RX_vect_num    USART_RXC_vect_num
#define USART0_UDRE_vect      USART_UDRE_vect
#define USART0_UDRE_vect_num  USART_UDRE_vect_num
#define USART0_TX_vect        USART_TXC_vect
#define USART0_TX_vect_num    USART_TXC_vect_num
#define ANALOG_COMP_vect      ANA_COMP_vect
#define ANALOG_COMP_vect_num  ANA_COMP_vect_num
#endif //EMBEDDED2_JORIX_ATMEGA32_H
