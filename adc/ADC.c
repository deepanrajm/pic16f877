// LCD module connections
sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
// End LCD module connections
unsigned int mv;
char *temp = "0000";

void main() 
{
TRISC=0x00;
TRISD=0x00;
TRISA=0xFF;
ADCON0 = 0x81;
//ADCON1 = 0xCE;
Lcd_Init(); // Initialize LCD
Lcd_Cmd(_LCD_CLEAR); // Clear display
Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off

while (1)
{
mV = ADC_Read(1); // Read sensor output from channel 1
 // ADC-1024 steps, Resolution is 4.88 mV (5000 mV/1024
temp[3] = (mV % 10)+48;
temp[2] = ((mV / 10) % 10)+48;
temp[1] = ((mv / 100) % 10)+48;
temp[0] = ((mV / 1000))+48;
Lcd_Out(1,2,temp);

}
}