void main() {
TRISD = 0x00;

while (1)
 {
 PORTD = 0x55;
 delay_ms(1000);
 PORTD = 0xAA;
 delay_ms(1000);
 }
}