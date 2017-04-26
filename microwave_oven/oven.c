unsigned int cnt;
unsigned int i=20;
unsigned int a;
int y[6];
void oven_display();
void interrupt ()
{

if(PORTB.F0==1)
{
i=i+10;
delay_ms(500);
}
else
{
  INTCON=0X00;
  cnt++;
  TMR0=96;
  INTCON=0xA0;
  }

}
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
void main()
 {
  TRISC=0X00;
  TRISD=0;
 
  oven_display();
  OPTION_REG.INTEDG=1;

while (1)
{

oven_display ();
}
 }
void oven_display()
{

OPTION_REG=0X84;
TMR0=96;
INTCON=0XA0;
cnt=0;
do
  {
  if(cnt==400)
  {
Lcd_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
Bytetostr(i, y);
LCD_OUT(1,2,"Remaining time");
LCD_OUT(2,1,y);
 i=i-1;
 PORTC.F0=1;
 PORTC.F1=1;
 delay_ms(100);
 cnt=0;
  }
else
  {
PORTC.F0=1;
PORTC.F1=1;
  }
  }
  while(i>0);
  PORTC.F0=0;
  PORTC.F1=0;
  delay_ms(1000);
  Lcd_Cmd(_LCD_CLEAR);
  LCD_OUT(1,2,"Completed");
  }