void state1();
void state2();
int i=0;
void main()
{
TRISB = 0xFF;
TRISC = 0x00;

while (1)
{
 if(PORTB.F0==0 && PORTB.F1==0)
 {
  state1();
 }
 else if (PORTB.F0==1 && PORTB.F1==0)
 {
  if (i=0)
  state1 ();
   i=1;
  }
 else if (PORTB.F0==1 && PORTB.F1==1)
 {
  state2 ();
 }
 else if (PORTB.F0==1 && PORTB.F1==0)
 {
  if (i=1)
  state2 ();
   i=0;
 }
 else
 {
  PORTC.F0=0;
  PORTC.F1=0;
  PORTC.F2=0;
  PORTC.F3=0;
 }
 }
 }
void state1()
  {
  PORTC.F0=1;
  PORTC.F1=0;
  PORTC.F2=0;
  PORTC.F3=0;
  }
void state2 ()
   {
    PORTC.F0=0;
    PORTC.F1=0;
    PORTC.F2=1;
    PORTC.F3=0;
   }

