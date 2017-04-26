unsigned int num1=0;
unsigned int num2=0;
unsigned int n1=0;
unsigned int n2=0;
unsigned int res=0;
char op;
char clear;
char op1[6];
unsigned short kp=0;
char keypadPort at PORTC;
int input_num();
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
void main()
 {
for(;;)
 {
 num1=0,num2=0,n1=0,n2=0,res=0;
while(1)
  {
          num1=input_num();
          if (num1=='+'||num1=='-'||num1=='*'||num1=='/' )
          {
             op=num1;
             break;
          }
          else if(num1==' ')
              goto CLEAR;
           else
           {
               n1=n1*10+num1;
               Lcd_Init();
               ByteToStr(n1, op1);
               LCD_Out(1,1,op1 );
          }
   }
          LCD_Chr(1,5,op);
   while(1)
   {
        num2=input_num();
        if (num2=='=')
          {
           break;
          }
          else if(num2==' ')
          goto CLEAR;
           else
           {
               n2=n2*10+num2;
               ByteToStr(n2, op1);
               LCD_Out(1,6,op1);
            }
   }
   if (num2=='=')
    LCD_Chr(1,10,num2);
   {
          switch (op)
          {
           case '+':
               res=n1+n2;
               break;
           case '-':
               res=n1-n2;
               break;
           case '*':
               res=n1*n2;
               break;
           case '/':
               res=n1/n2;
               break;

          }
  }

  ByteToStr(res, op1);
  LCD_Out(2,6,"Answer");
  LCD_Out(2,14,op1 );
  num1=input_num();
CLEAR:
 LCD_Cmd(_LCD_CLEAR);
}
}
 //keypad program
int input_num()
 {
 Keypad_Init();
 do
 kp=Keypad_Key_Click();
 while(!kp);
 switch(kp)
 {
 case 1: kp= 7; break;
 case 2: kp= 4; break;
 case 3: kp= 1; break;
 case 4: kp= 32; break;//space
 case 5: kp= 8; break;
 case 6: kp= 5; break;
 case 7: kp= 2; break;
 case 8: kp= 0; break;
 case 9: kp= 9; break;
 case 10: kp= 6; break;
 case 11: kp= 3; break;
 case 12: kp= 61; break;//=
 case 13: kp= 47; break;//%
 case 14: kp= 42; break; //*
 case 15: kp= 45; break;//-
 case 16: kp= 43; break; //+
 }
return kp;
}