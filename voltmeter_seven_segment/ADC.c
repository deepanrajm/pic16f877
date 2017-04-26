//Voltmeter with LCD & Seven segment
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

unsigned int value;
unsigned int mV;
char *temp = "0000";
char *bin1 = "0000";
char *bin2 = "0000";
char *bin3 = "0000";
char *bin4 = "0000";
void main ()
{
int i;
TRISC=0x00;
TRISD=0x00;
TRISA=0xFF;
TRISB=0x00;
ADCON0 = 0x81;
ADCON1 = 0xCE;
Lcd_Init();
PORTB=0x00;
PORTC=0x00;
while (1)
{
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
mV = ADC_Read(1);
value = mV*4.88; // Read sensor output from channel 1
temp[3] = (value % 10)+48;
temp[2] = ((value / 10) % 10)+48;
temp[1] = ((value / 100) % 10)+48;
temp[0] = ((value / 1000))+48;
Lcd_Out(1,6,temp); Lcd_Out(1,10," mV");
delay_ms(1000); 
Lcd_Cmd(_LCD_CLEAR);
for(i = 0; i<=3; i++)
{ 
bin1[i]=temp[0]%2;
temp[0] = temp[0]/2;
}
for(i = 0; i<=3; i++)
{
bin2[i]=temp[1]%2;
temp[1] = temp[1]/2;
}
for(i = 0; i<=3; i++)
{
bin3[i]=temp[2]%2;
temp[2] = temp[2]/2;
}
for(i = 0; i<=3; i++)
{
bin4[i]=temp[3]%2;
temp[3] = temp[3]/2;
}
PORTB.F0 = bin1[0];
PORTB.F1 = bin1[1];
PORTB.F2 = bin1[2];
PORTB.F3 = bin1[3];
PORTB.F4 = bin2[0];
PORTB.F5 = bin2[1];
PORTB.F6 = bin2[2];
PORTB.F7 = bin2[3];
PORTC.F0 = bin3[0];
PORTC.F1 = bin3[1];
PORTC.F2 = bin3[2];
PORTC.F3 = bin3[3];
PORTC.F4 = bin4[0];
PORTC.F5 = bin4[1];
PORTC.F6 = bin4[2];
PORTC.F7 = bin4[3];
}
}