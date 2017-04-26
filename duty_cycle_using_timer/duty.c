unsigned int count;
void On_pulse ();
void Off_pulse ();
void interrupt ()
{
  INTCON=0x00;
  count++;
  TMR0=96;
  INTCON=0xA0;
}
void main()
{
TRISC=0x00;
while (1)
{
On_pulse();
On_pulse();
On_pulse();
Off_pulse();
Off_pulse();
}
}
void On_pulse()
{
OPTION_REG=0x84;
TMR0=96;
INTCON=0xA0;
count=0;
do
{
if (count==400)
 {
 PORTC.F0=1;
 count=0;
 break;
}
}
while (1) ;

}
void Off_pulse()
{
OPTION_REG=0x84;
TMR0=96;
INTCON=0xA0;
count=0;
do
{
if (count==400)
 {
 PORTC.F0=0;
 count=0;
 break;
 }
 
}
while (1);
}