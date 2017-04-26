void main() {
TRISD = 0x00;
TRISB = 0xFF;

while (1)
 {
 if (PORTB.F0==1)
 {
 PORTD = 0x55;
 delay_ms(1000);
 PORTD = 0xAA;
 delay_ms(1000);
 }
 else
 {
 PORTD = 0x00;
 }
 }
}