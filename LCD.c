#include<p18f4580.h>
void Lcd_cmd(char);
void Lcd_Data(char ); 

#define RS PORTCbits.RC0
#define E PORTCbits.RC1
#define x 50

void delay(int a);

void main()
{
// vaiable initialisation
char name[]= "Piyush Gondane ";
int i;

// one tim eexecution
TRISD = 0X00; //CONFIH AS DIGITAL O.P.
TRISCbits.RC0 = 0;
TRISCbits.RC1 = 0;

// LCD INIT
Lcd_cmd(0x0e); //LCD ON, Cursor ON
Lcd_cmd(0x01); // Clear screen
Lcd_cmd(0x06); //Inc Cursor
Lcd_cmd(0x038); // 2 lines, 5x7 matrix
Lcd_cmd(0x80); //1st Row, 1st Pos/Col
while(1)
{
for(i=0;name[i]!='\0';i++)
{
Lcd_Data(name[i]);
}
Lcd_cmd(0x01);
}
}
void Lcd_cmd(char cm) // cm = 0x01
{
PORTD = cm;
RS = 0; // Command Mode
E =1;
E = 0;
}
void Lcd_Data(char dt) //dt = H
{
PORTD = dt;
RS = 1;// data(char)
E = 1;
delay(x);
E = 0;
}
void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<a;j++);
}
