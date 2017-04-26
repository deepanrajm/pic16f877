unsigned char DICE[] = {0,0x08,0x22,0x2A,0x55,0x5D,0x77};
unsigned char pattern1,pattern2;
unsigned int i=1;
void main() 
{
TRISB=0x00;
TRISD=0x00;
TRISC=0xFF;
PORTB=0x00;
PORTD=0x00;

while (1)
{
if (PORTC.F0==1)
{
pattern1 = DICE[i];
pattern2 = DICE[i+2];
PORTB=pattern1;
PORTD=pattern2;
i=0;
delay_ms (1000);
}
i++;

if(i==7)
{
i=1;
}
}

}

