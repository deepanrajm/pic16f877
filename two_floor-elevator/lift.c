// LCD module connections
sbit LCD_RS at RC2_bit;
sbit LCD_EN at RC3_bit;
sbit LCD_D4 at RC4_bit;
sbit LCD_D5 at RC5_bit;
sbit LCD_D6 at RC6_bit;
sbit LCD_D7 at RC7_bit;

sbit LCD_RS_Direction at TRISC2_bit;
sbit LCD_EN_Direction at TRISC3_bit;
sbit LCD_D4_Direction at TRISC4_bit;
sbit LCD_D5_Direction at TRISC5_bit;
sbit LCD_D6_Direction at TRISC6_bit;
sbit LCD_D7_Direction at TRISC7_bit;
// End LCD module connections
int load;
int temp;
int i=0;
void overload();
void lift_up();
void lift_down();
void door_open();
void door_close();
void grnd_floor();
void one_floor();
void two_floor() ;
void initlcd();
void main()
{
TRISA=0xFF;
TRISB=0x00;
TRISC=0x00;
TRISE=0xFF;
TRISD=0x00;
ADCON0=0x81;
ADCON1=0xCE;
PORTB=0x00;
PORTD=0x00;
initlcd();
Lcd_Out(1,2,"welcome");
delay_ms(1000);

while (1)
{
temp = ADC_Read(0);
if (temp>= 700)
{
overload ();
}
else if (PORTA.F1==1)
   {
    if (i==0)
       {
       door_open();
       initlcd();
       grnd_floor();
       }
    else if (i==1)
       {
        lift_down();
        door_open();
        initlcd();
        grnd_floor();
       }
    else if (i==2)
       {
       lift_down();
       lift_down();
       door_open();
       initlcd();
       grnd_floor();
       }
   }
else if (PORTA.F2==1)
{
      if (i==0)
       {
       lift_up();
       door_open();
       initlcd();
       one_floor();
       }
    else if (i==1)
       {
        door_open();
        initlcd();
        one_floor();
       }
    else if (i==2)
       {
       lift_down();
       door_open();
       initlcd();
       one_floor();
       }
}
else if (PORTA.F3==1)
{
if (i==0)
       {
       lift_up();
       lift_up();
       door_open();
       initlcd();
       two_floor();
       }
    else if (i==1)
       {
        lift_up();
        door_open();
        initlcd();
        two_floor();
       }
    else if (i==2)
       {
       door_open();
       initlcd();
       two_floor();
       }
}
else if (PORTA.F4==1)
{
if (i==0)
       {
       door_close();
       door_open();
       initlcd();
       grnd_floor();
       }
    else if (i==1)
       {
        door_close();
        lift_down();
        door_open();
        initlcd();
        grnd_floor();
       }
    else if (i==2)
       {
       door_close();
       lift_down();
       lift_down();
       door_open();
       initlcd();
       grnd_floor();
       }
}
else if (PORTA.F5==1)
{
 if (i==0)
       {
       door_close();
       lift_up();
       door_open();
       initlcd();
       one_floor();
       }
    else if (i==1)
       {
        door_close();
        door_open();
        initlcd();
        one_floor();
       }
    else if (i==2)
       {
       door_close();
       lift_down();
       door_open();
       initlcd();
       one_floor();
       }
}
else if (PORTE.F0==1)
{
if (i==0)
       {
       door_close();
       lift_up();
       lift_up();
       door_open();
       initlcd();
       two_floor();
       }
    else if (i==1)
       {
        door_close();
        lift_up();
        door_open();
        initlcd();
        two_floor();
       }
    else if (i==2)
       {
       door_close();
       door_open();
       initlcd();
       two_floor();
       }
}
}
}
void initlcd()
{
Lcd_Init(); // Initialize LCD
delay_ms(100);
Lcd_Cmd(_LCD_CLEAR); // Clear display
Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
}
void lift_up()
{
PORTB = 0x60;//0
delay_ms(250);
PORTB = 0x30; //90
delay_ms(250);
PORTB = 0x90; //180
delay_ms(250);
PORTB = 0xC0; //270
delay_ms(250);
PORTB = 0x60; //0
i=i+1;
}
void lift_down()
{
PORTB = 0x60;
delay_ms(250);
PORTB = 0xC0;
delay_ms(250);
PORTB = 0x90;
delay_ms(250);
PORTB = 0x30;
delay_ms(250);
PORTB = 0x60;
i=i-1;
}
void door_open()
{
unsigned int j;
for(j=0;j<20;j++)
{
PORTC.F0=1;
delay_us(600); //Servo at -90 deg
PORTC.F0=0;
delay_us(20000);
}
delay_ms(50);
for(j=0;j<20;j++)
{
PORTC.F0=1;
delay_us(1850); //Servo at 60 deg
PORTC.F0=0;
delay_us(20000);
}
delay_ms(150);
}
void door_close()
{
unsigned int j;
for(j=0;j<20;j++)
{
PORTC.F0=1;
delay_us(1166); //Servo at -60 deg
PORTC.F0=0;
delay_us(20000);
}
delay_ms(1000);
}
void grnd_floor()
{
Lcd_Out(1,3,"Ground Floor");
delay_ms(1000);
PORTB.F0=0;
PORTB.F1=0;
PORTB.F2=0;
PORTB.F3=0;
delay_ms(1000);
}
void one_floor()
{
Lcd_Out(1,3,"First Floor");
delay_ms(1000);
PORTB.F0=1;
PORTB.F1=0;
PORTB.F2=0;
PORTB.F3=0;
delay_ms(1000);
}

void two_floor()
{
Lcd_Out(1,3,"Second Floor");
delay_ms(1000);
PORTB.F0=0;
PORTB.F1=1;
PORTB.F2=0;
PORTB.F3=0;
delay_ms (1000);
}
void overload()
{

PORTB=0x00;
Lcd_Out(2,3,"Overload");

}