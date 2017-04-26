void main() 
{
TRISC=0;
TRISB=0xFF;
OPTION_REG.INTEDG=1; //Rising edge enable
INTCON.GIE=1;    //global interrupt
INTCON.INTE=1;
while (1)
{
PORTC=0x55;
delay_ms(1000);
PORTC=0xAA;
delay_ms(1000);
}
}
void interrupt()      //Default Interrupt function
{
INTCON.INTF=0;
PORTC=0xFF;
delay_ms(1000);
PORTC=0X00;
delay_ms(1000);
}


