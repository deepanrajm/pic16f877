void dc_motor_clock();
void dc_motor_anti();
void dc_stop();
void main()
{
TRISD = 0x00;
TRISB = 0xFF;
TRISC = 0x00;
TRISA = 0xFF;
ADCON1 =0x06;

while (1)
 {
  if (PORTB.F0==1 && PORTA.F0==0)
  {
  PORTD=0x00;
  dc_motor_clock();
 }
 else if (PORTB.F0==0 && PORTA.F0==1)
 {
  PORTD=0x00;
  dc_motor_anti();
 }
 
 else
 {
 PORTD = 0x55;
 delay_ms(1000);
 PORTD = 0xAA;
 delay_ms(1000);
 dc_stop();
 }
 }
}
  void dc_motor_clock()
{
PORTC.F0=1;
PORTC.F1=0;
}

  void dc_motor_anti()
{
PORTC.F0=0;
PORTC.F1=1;
}
 void dc_stop()
{
PORTC.F0=0;
PORTC.F1=0;
}