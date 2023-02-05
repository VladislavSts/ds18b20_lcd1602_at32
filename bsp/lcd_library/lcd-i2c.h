#include "at32f403a_407.h"

void LCD_Init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_put_cur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_clear (void);

uint8_t i2c_master_transmit(uint16_t address, uint8_t* pdata, uint16_t size);

