//
// Created by joris on 21-2-2019.
//

#include "jorix_lcd.h"

uint8_t cursorLocations[4] = {0, 64, 20, 84};

// Define a prototype here instead of the header because it should be internal.
void lcdWrite(unsigned char);

/**
 * This function will setup the LCD and initiate the startup sequence.
 */

void initLCD ()
{
  // Setup I/0)
  LCD_DDR_CRTL |= 1 << LCD_ENABLE_SIGNAL_PIN |  // Setup as output, for starting a read or write operation.
          1 << LCD_READ_WRITE_PIN |     // Setup as output, to switch between read or write mode.
          1 << LCD_FUNCTION_SELECT_PIN; // Setup as output, for selecting the data or instruction register.
  _delay_ms (15); // Wait for vcc to rise before sending commands to the LCD.

  lcdWriteCommand (LCDI_CLEAR_DISPLAY); // Make sure the display is empty.
  _delay_ms(2);

  lcdWriteCommand (LCDI_FUNCTION_SET|LCDF_FUNC_SET_8BITMODE|LCDF_FUNC_SET_2LINE);// 0b0011 1000
  _delay_us(50);

  // Enable the LCD and a static cursor.
  lcdWriteCommand ( LCDF_CRTL_CURSOR_ON | LCDF_CRTL_DISPLAY_ON | LCDI_DISPLAY_CRTL );

  _delay_us(50);
  lcdWriteCommand (LCDI_CLEAR_DISPLAY); // Make sure the display is empty.
}
/**
 * This function is used to check if the LCD is preoccupied or if it accepts new data or commands.
 */
void lcdCheckAvailability ()
{
  // First set the data pins to input so we can receive data from the LCD.
  LCD_DDR_DATA = 0;
  // Select read mode from the LCD, RW = 1
  LCD_CRTL_PORT |= 1<<LCD_READ_WRITE_PIN;
  // Select the command register, this now reads the busy flag and address counter.  RS = 0
  LCD_CRTL_PORT &= ~(1<<LCD_FUNCTION_SELECT_PIN); // todo check if this is correct.

  /**
   * The data we read from the LCD is:
   *      Data pin 7  = The busy flag,
   *                      1 means its busy and won't accept commands,
   *                      0 ready to receive a command.
   *      Data pin 0-6 = The address counter
   */
  while(LCD_DATA_PORT >= 0x80)
    //while(LCD_DATA_PORT & 0x80 )
    {
      lcdStartTransaction(); // Read in data from the LCD.
    }

  // Set the data pins as output so we can write to the LCD again.
  LCD_DDR_DATA = 0xFF;

}

/**
 * This function will start a read or write command and waits for some clock cycles
 * so the LCD has time to process it.
 */
void lcdStartTransaction ()
{
  // Send the enable signal to the LCD to start the transaction.
  LCD_CRTL_PORT |= 1<<LCD_ENABLE_SIGNAL_PIN;

  // Wait 2 clock circles so the LCD has some time to detect the transaction.
  asm volatile("nop");
  asm volatile("nop");

  // The LCD should have received it so close the transaction.
  LCD_CRTL_PORT &= ~(1<<LCD_ENABLE_SIGNAL_PIN); // todo check if this is correct.
}

/**
 * This function writes data and commands to the LCD. Before calling this function you should select
 * a register, eigther the command register (RS = 0) or data register (RS=1).
 * @param data The byte that will be available on the data port of the LCD.
 */
void lcdWrite(unsigned char data)
{
  // Select the instruction register in write mode. (R\W=0, RS=0 || RS=1)
  LCD_CRTL_PORT &= ~(1<<LCD_READ_WRITE_PIN);

  // Output the command on the data port so it will be available when we send the Enable signal.
  LCD_DATA_PORT = data;

  // Send the command to the LCD.
  lcdStartTransaction();

  // Clear the executed command from the data port.
  LCD_DATA_PORT = 0;
}

/**
 * Used to send a command to the LCD.
 * @param command A action on the display, check the defines with the prefix: LCD_COMMAND_
 */
void lcdWriteCommand (unsigned char command)
{
  lcdCheckAvailability();
  // Select the instruction register on the LCD, RS = 0
  LCD_CRTL_PORT &= ~(1<<LCD_FUNCTION_SELECT_PIN);

  // Write the command to the LCD
  lcdWrite (command);
}

/**
 * Used to send a character to the LCD.
 * @param character A ASCII character to display on the LCD.
 */
void lcdWriteCharacter (unsigned char character)
{
  lcdCheckAvailability();
  // Select the data register on the LCD, RS = 1
  LCD_CRTL_PORT |= 1 << LCD_FUNCTION_SELECT_PIN;

  // Write the character to the display.
  lcdWrite (character);
}

/**
 * Used to send a string to the LCD.
 * @param character A pointer to the string to display on the LCD.
 */
void lcdWriteString(char *string)
{
  // Send each character to the LCD until the 0 termination character is reached.
  while ( *string > 0)
    {
      // Write the character and increase the pointer by 1.
      lcdWriteCharacter (*string++);
    }
}

/**
 * Used to move the cursor to a specific location on the LCD
 * @param x Move cursor on the x axis.
 * @param y Move cursor on the y axis.
 */
void lcdMoveCursorTo(uint8_t x, uint8_t y)
{
  lcdWriteCommand( 0x80 + cursorLocations[y-1] + (x-1) );
}

/**
 * Write a string to the LCD at a specific location.
 * @param x Location in the line to print.
 * @param y Line number to print on.
 * @param string The string to display.
 */
void lcdWriteStringAt(uint8_t x, uint8_t y, char *string)
{
  lcdMoveCursorTo (x, y);
  lcdWriteString (string);
}

/**
 * Write a string to the LCD at a specific location.
 * @param x Location in the line to print.
 * @param y Line number to print on.
 * @param string The string to display.
 */
void lcdWriteFixedWidthStringAt(uint8_t x, uint8_t y, char *string, int width )
{
  int len = strlen(string);
  memset( string+len, ' ', width );
  string[len + width] = '\0';
  lcdMoveCursorTo (x, y);
  lcdWriteString (string);
}

/**
 *
 * @param x
 * @param y
 * @param amount memset( dest,' ',sizeof(dest));
 */
void lcdClearCharactersAt(uint8_t x, uint8_t y, char amount)
{
  lcdMoveCursorTo (x, y);
  for(int i=0; i<amount; i++)
  {
    lcdWriteString (" ");
  }
}

void lcdClear()
{
    lcdWriteCommand (LCDI_CLEAR_DISPLAY); // Make sure the display is empty.
}
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
