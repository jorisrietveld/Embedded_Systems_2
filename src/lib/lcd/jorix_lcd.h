//
// Created by joris on 21-2-2019.
//

#ifndef EMBEDDEDSYSTEMS2_JORIX_LCD_H
#define EMBEDDEDSYSTEMS2_JORIX_LCD_H

//#include "lib/io/jorix_atmega32.h"
#include <avr/io.h>     // Used to configure the I/O pins connected to the LCD.
#include <util/delay.h>  // Used to accurately time data send to the LCD.

#include <stdlib.h>     // Used for numeral to ascii conversions.
#include <inttypes.h>   // train
#include <string.h>     //

// Liquid cristal display instructions.
#define LCDI_CLEAR_DISPLAY    0x01  // Clear the display by writing spaces to it and reset cursor to pos 0.
#define LCDI_RETURN_HOME      0x02  // Moves the cursor to pos 0 by setting DDRAM to address 0.
#define LCDI_ENTRY_MODE_SET   0x04  // Sets the cursor moving behavour see the entry mode flags below.
#define LCDI_DISPLAY_CRTL     0x08  // Enables/Disables the display or cursor. Sets the cursor effect (blink).
#define LCDI_CURSOR_SHIFT     0x10  // Moves the cursor to a specific location on the matrix.
#define LCDI_FUNCTION_SET     0x20  // Configures 8/4 bit mode, x/y dimentions and the character font.
#define LCDI_SET_CGRAM_ADDR   0x40  // Sets the CGRAM adddress into the address counter.
#define LCDI_SET_DDRAM_ADDR   0x80  // Sets the DDRAM adddress into the address counter.
//0011 0000 todo remove
//0000 1110 todo remove
// flags for display entry mode
#define LCDF_ENTRY_RIGHT  0x00
#define LCDF_ENTRY_LEFT   0x02
#define LCDF_ENTRY_SHIFT_INCREMENT 0x01
#define LCDF_ENTRY_SHIFT_DECREMENT 0x00

// flags that can be combined with the display control instruction.
#define LCDF_CRTL_DISPLAY_ON  0x04 // Enables the display.
#define LCDF_CRTL_DISPLAY_OFF 0x00 // Disables the display.
#define LCDF_CRTL_CURSOR_ON   0x02 // Enables the cursor.
#define LCDF_CRTL_CURSOR_OFF  0x00 // Disables the cursor.
#define LCDF_CRTL_BLINK_ON    0x01 // Enables blinking cursor mode.
#define LCDF_CRTL_BLINK_OFF   0x00 // Disables blinking cursor mode.

// Flags that can be combined with the cursor shift instruction.
#define LCDF_SHIFT_MOVE_DISPLAY 0x08 // Moves the display relative to the cursor.
#define LCDF_SHIFT_MOVE_CURSOR  0x00 // Moves the cursor relative to the display.
#define LCDF_SHIFT_TO_RIGHT     0x04 // Moves the cursor or display to the right.
#define LCDF_SHIFT_TO_LEFT      0x00 // Moves the cursor or display to the left.

// flags that can be combined with the function set instruction.
#define LCDF_FUNC_SET_8BITMODE  0x10 // Sets the LCD into 8 bit mode.
#define LCDF_FUNC_SET_4BITMODE  0x00 // Sets the LCD into 4 bit mode.
#define LCDF_FUNC_SET_2LINE     0x08 // Sets the
#define LCDF_FUNC_SET_1LINE     0x00 // Sets the
#define LCDF_FUNC_SET_5x10DOTS  0x04 // Sets the
#define LCDF_FUNC_SET_5x8DOTS   0x00 // Sets the

#define LCD_DATA_PORT PORTC // This port will be used to send data to the LCD
#define LCD_DDR_DATA  DDRC
#define LCD_CRTL_PORT PORTD // This port will be used to control the LCD.
#define LCD_DDR_CRTL  DDRD

#define LCD_ENABLE_SIGNAL_PIN     7 // Used to start read or write data from or to the display.
#define LCD_READ_WRITE_PIN        6 // Used to switch the LCD between read and write mode. 0 write, 1 read.
#define LCD_FUNCTION_SELECT_PIN   5 // Used to switch between instruction register and data register.
#define LCD_DB_0_PIN   0
#define LCD_DB_1_PIN   1
#define LCD_DB_2_PIN   2
#define LCD_DB_3_PIN   3
#define LCD_DB_4_PIN   4
#define LCD_DB_5_PIN   5
#define LCD_DB_6_PIN   6
#define LCD_DB_7_PIN   7
/**
 * This function will setup the LCD and initiate the startup sequence.
 */
void initLCD();

/**
 * This function is used to check if the LCD is preoccupied or if it accepts new data or commands.
 */
void lcdCheckAvailability(void);

/**
 * This function will start a read or write command and waits for some clock cycles
 * so the LCD has time to process it.
 */
void lcdStartTransaction(void);

/**
 * Used to send a command to the LCD.
 * @param command A action on the display, check the defines with the prefix: LCD_COMMAND_
 */
void lcdWriteCommand(unsigned char command);

/**
 * Used to send a character to the LCD.
 * @param character A ASCII character to display on the LCD.
 */
void lcdWriteCharacter(unsigned char character);

/**
 * Used to send a string to the LCD.
 * @param character A pointer to the string to display on the LCD.
 */
void lcdWriteString(char *string);

/**
 * Used to move the cursor to a specific location on the LCD
 * @param x Move cursor on the x axis.
 * @param y Move cursor on the y axis.
 */
void lcdMoveCursorTo(uint8_t x, uint8_t y);

/**
 * Write a string to the LCD at a specific location.
 * @param x Location in the line to print.
 * @param y Line number to print on.
 * @param string The string to display.
 */
void lcdWriteStringAt(uint8_t x, uint8_t y, char *string);

/**
 *
 * @param x
 * @param y
 * @param amount
 */
void lcdClearCharactersAt(uint8_t x, uint8_t y, char amount);

void lcdWriteFixedWidthStringAt(uint8_t x, uint8_t y, char *string, int width );

void lcdClear();
void lcdHome();

void lcdOn();
void lcdOff();

void lcdBacklightOn();
void lcdBacklightOff();

void lcdEnableCursor();
void lcdDisableCursor();

void lcdEnableBlink();
void lcdDisableBlink();

void lcdWriteLeftToRight();
void lcdWriteRightToLeft();

void lcdEnableAutoScroll();
void lcdDisableAutoScroll();

void lcdCursorMoveLeft();
void lcdCursorMoveRight();

void lcdScrollLeft();
void lcdScrollRight();


#endif //EMBEDDEDSYSTEMS2_JORIX_LCD_H
