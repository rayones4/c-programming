1. Write an ALP to find the sum of first 10 integer numbers.

area sumofint,code,readonly 
entry  
__main 
loop  
export __main 
mov r0, #10 
mov r1, #00 
add r1,r0 
subs r0,#1 
bne loop 
stop b stop 
end 

2. Write an ALP to multiply two 16-bit binary numbers. 

area multipli,code,readonly 
entry   
export __main 
num1 dcd 0x5000 
num2 dcd 0x4000 
__main 
ldr r0, num1 
ldr r1, num2   
mul r3,r1,r0 
ldr r4,=product  
str r3,[r4] 
stop b stop  
area result,data,readwrite  
product dcd 0x0 
end

3. Write an ALP to find factorial of a number 
area factof,code,readonly 
entry 
export __main 
__main 
fact 
mov r0,#12 
mov r1,r0 
subs r1,r1,#1 
cmp r1,#1 
beq stop 
mul r3,r0,r1 
mov r0,r3 
bne fact 
stop b stop

4. Write an ALP to add an array of 16 bit numbers and store the 32 bit result in internal 
RAM 
area addition,code,readonly 
entry 
__main 
next 
export __main 
ldr r0,=array 
ldr r5,=sum 
mov r1,#0 
mov r4,#0 
cmp r1,#5 
beq store 
ldrh r3,[r0],#2 
adc r4,r4,r3 
add r1,r1,#1 
loop b next 
store str r4,[r5] 
stop b stop 
area dataseg1,data,readonly 
array dcw 0x1111,0x1122,0x1133,0x1144,0x1155 
align 
area dataseg2,data 
sum dcd 0 
end

5. Write an ALP to find the square of a number(1 to 10) using look-up table 

area square,code,readonly 
entry 
  export __main 
__main 
  ldr r0,=table1 
  ldr r1,=8 
  mov r1,r1,lsl#0x2 
  add r0,r0,r1 
  ldr r2,[r0] 
table1   dcd 0x00000000 
  dcd 0x00000001 
  dcd 0x00000004 
  dcd 0x00000009 
  dcd 0x00000010 
  dcd 0x00000019 
  dcd 0x00000024 
  dcd 0x00000031 
  dcd 0x00000040 
  dcd 0x00000051 
  dcd 0x00000064 
  end 

  6. Write an ALP to find the largest/smallest number in an array of 32-bit 
numbers.(use ”movls”=largest/ “movhi”=smallest) 

area prog, code, readonly  
entry  
export __main  
__main  
ldr r0,=array  
mov r1,#6  
ldr r3,[r0],#04  
up  
ldr r4,[r0],#04  
cmp r3,r4  
movls r3,r4 ;(//movls is to get the largest number, change it to movhi to get smallest 
number)  
sub r1,r1,#1  
cmp r1,#0  
bne up  
ldr r0,=ls  
str r3,[r0]  
stop b stop  
area sbc, data,readonly  
array dcd 0x33333333, 0x22222222, 0x55555555, 0x11111111, 0x77777777, 0xffffffff, 
0x12345672  
align  
area dst,data  
ls dcd 0  
align  
end 

1) Interface a stepper motor and rotate it in clockwise and anti-clockwise direction. 
//Controlling stepper motor through keys 
#include <LPC17xx.H> 
void delay(unsigned int count) 
{ 
unsigned int j=0,i=0; 
for(j=0;j<count;j++) 
{ 
for(i=0;i<5000;i++); 
}} 
int main (void) 
{ 
unsigned int del=50; 
LPC_GPIO1->FIODIR = 0x03C00000; 
uint32_t i; 
while(1) 
{ 
if (!(LPC_GPIO1->FIOPIN & (1<<14))) 
{ 
for ( i=0; i<500; i++) 
{ 
LPC_GPIO1->FIOPIN =0x02000000; 
delay(del); 
LPC_GPIO1->FIOPIN =0x01000000; 
delay(del); 
LPC_GPIO1->FIOPIN =0x00800000; 
delay(del); 
LPC_GPIO1->FIOPIN =0x00400000; 
delay(del); 
if (!(LPC_GPIO1->FIOPIN & (1<<15)))
break; }} 
if (!(LPC_GPIO1->FIOPIN & (1<<15))) 
{ 
for ( i=0; i<500; i++) 
{ 
LPC_GPIO1->FIOPIN =0x00400000; 
delay(del); 
LPC_GPIO1->FIOPIN =0x00800000; 
delay(del); 
LPC_GPIO1->FIOPIN =0x01000000; 
delay(del); 
LPC_GPIO1->FIOPIN =0x02000000; 
delay(del); 
if (!(LPC_GPIO1->FIOPIN & (1<<14))) 
break; 
}}}}

2) Interface a DAC and generate Triangle and Square waveforms. 
//Square Wave 
#include <LPC17xx.H> 
#define voltage 1024 
#define freq 120000 
int main (void) 
{ 
uint32_t m; 
LPC_PINCON->PINSEL1 |= (1<<21); 
while(1) 
{ 
LPC_DAC->DACR = (voltage/2 << 6); 
for(m = freq; m > 1; m--); 
LPC_DAC->DACR = (voltage << 6); 
for(m = freq; m > 1; m--); 
} 
} 
// DAC-Triangle wave 
#include <LPC17xx.H> 
#define voltage 1024 
int main (void) 
{ 
uint32_t i = 0; 
LPC_PINCON->PINSEL1 |= (1<<21); 
while(1) 
{
for(i = 0; i < voltage; i++) 
LPC_DAC->DACR = (i << 6); 
for(i = voltage; i > 0; i--) 
LPC_DAC->DACR = (i << 6); 
} 
}

//3.1)  //7-SEG Counter 
#include <LPC17xx.H> 
unsigned char data7[] = 
{0x88,0xeb,0x4c,0x49,0x2b,0x19,0x18,0xcb,0x8,0x9,0xa,0x38,0x9C,0x68,0x1c,0x1e}; 
int main (void) 
{ 
unsigned int i,j; 
unsigned int count=0; 
LPC_GPIO2->FIODIR = 0x000000FF; 
LPC_GPIO1->FIODIR = 0x3C000000; 
//Seven seg on PORT2 
//Dig control on PORT1 are output 
while(1) 
{ 
++count; 
if (count > 0xFFFF) 
count = 0; 
for (i=0; i < 5000; i++)//change to inc/dec speed of count 
{ 
LPC_GPIO2->FIOPIN = data7[count & 0x000F];  
LPC_GPIO1->FIOSET = (1 << 26);  
for (j=0;j<500;j++); 
LPC_GPIO1->FIOCLR = (1 << 26); 
LPC_GPIO2->FIOPIN = data7[(count & 0x00F0)>>4]; 
LPC_GPIO1->FIOSET = (1<<27); 
for (j=0;j<500;j++); 
LPC_GPIO1->FIOCLR = (1 << 27); 
LPC_GPIO2->FIOPIN = data7[(count & 0x0F00)>>8];  
LPC_GPIO1->FIOSET = (1<<28); 
for (j=0;j<500;j++); 
LPC_GPIO1->FIOCLR = (1<<28); 
LPC_GPIO2->FIOPIN = data7[(count & 0xF000)>>12];  
LPC_GPIO1->FIOSET = (1<<29);  
for (j=0;j<500;j++); 
LPC_GPIO1->FIOCLR = (1<<29); 
} 
} 
} 

4) Interface a simple Switch and display its status trough Relay, Buzzer and LED 

#include<LPC17xx.H>  
int main (void) 
{  
unsigned int i,j;  
LPC_GPIO1->FIODIR&=~(0x003FC000); //Keys as input 
LPC_GPIO3->FIODIR=(1<<25); //Buzzer enable 
LPC_GPIO0->FIODIR=0x02000FF0; 
// LED and Relay as output 
while(1)  
{  
LPC_GPIO3->FIOCLR=(1<<25); //Buzzer off 
LPC_GPIO0->FIOPIN&=~(0x00000FF0); //LED off 
for(i=14;i<20;i++)  
{  
if (!(LPC_GPIO1->FIOPIN & (1<<i)))  
{  
LPC_GPIO3->FIOSET=(1<<25); // Buzzer on 
LPC_GPIO0->FIOSET=(1<<(i-10)); 
for(j=5000;j>0;j--);  
}}  
if (!(LPC_GPIO1->FIOPIN & (1<<20))) 
// if key 20 is pressed 
{  
LPC_GPIO0->FIOSET=(1<<25); //Relay on 
LPC_GPIO0->FIOSET=(1<<10);  
}  
if (!(LPC_GPIO1->FIOPIN & (1<<21))) 
// if key 21 is pressed 
{  
LPC_GPIO0->FIOCLR=(1<<25); // Relay off 
LPC_GPIO0->FIOSET=(1<<11);  
}}} 
  
