void ServoActivate()
{
unsigned int i;
for(i=0;i<20;i++)
{
PORTA.F0=1;
delay_us(600); //Servo at -90 deg
PORTA.F0=0;
delay_us(20000);
}
delay_ms(1000);
for(i=0;i<20;i++)
{
PORTA.F0=1;
delay_us(1166); //Servo at -60 deg
PORTA.F0=0;
delay_us(20000);
}
delay_ms(1000);
for(i=0;i<20;i++)
{
PORTA.F0=1;
delay_us(1333); //Servo at -30 deg
PORTA.F0=0;
delay_us(20000);
}
delay_ms(1000);
for(i=0;i<20;i++)
{
PORTA.F0=1;
delay_us(1500); //Servo at 0 deg
PORTA.F0=0;
delay_us(20000);
}
delay_ms(1000);
for(i=0;i<20;i++)
{
PORTA.F0=1;
delay_us(1666); //Servo at 30 deg
PORTA.F0=0;
delay_us(20000);
}
delay_ms(1000);
for(i=0;i<20;i++)
{
PORTA.F0=1;
delay_us(1850); //Servo at 60 deg
PORTA.F0=0;
delay_us(20000);
}
delay_ms(1000);
for(i=0;i<20;i++)
{
PORTA.F0=1;
delay_us(2400); //Servo at 90 deg
PORTA.F0=0;
delay_us(20000);
}
delay_ms(1000);
}
void main()
 {
TRISA = 0x00;
ADCON1 = 0x87;
while (1)
{
 ServoActivate();
}
}