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
 char i;
void main(){
Lcd_Init(); // Initialize LCD
Lcd_Cmd(_LCD_CLEAR); // Clear display
Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
Lcd_Out(1,3,"Robert Downey"); // Write text in first row
Lcd_Out(2,8,"IN"); // Write text in second row
Delay_ms(2000);
Lcd_Cmd(_LCD_CLEAR); // Clear display
Lcd_Out(1,6,"IRON MAN"); // Write text in first row
Lcd_Out(2,8,"SHERLOCK"); // Write text in second row
//Delay_ms(2000);

while(1) { // Endless loop
Lcd_Out(1,6,"IRON MAN"); // Write text in first row
Lcd_Out(2,8,"SHERLOCK");
for(i=0; i<5; i++) { // Move text to the left 7 times
Lcd_Cmd(_LCD_SHIFT_RIGHT);
delay_ms(500);
}
for(i=0; i<8; i++) { // Move text to the right 7 times
Lcd_Cmd(_LCD_SHIFT_LEFT);
delay_ms(500);
}
Lcd_cmd(_LCD_CLEAR);
}
}