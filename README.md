ALL LOGIC GATES : module all_ gates (A, B, op_not, op_or, op_and, op_nor, op_nand,
op_xor, op_xnor);
input A, B;
output op_not,op_or,op_and,op_nor ,op_nand ,op_xor, op_xnor;
assign op_not = ~ A;
assign op_or = ~ A | B;
assign op_and = A & B;
assign op_nor = ~(A | B);
assign op_nand = ~( A &B);
assign op_xor = A ^ B;
assign op_xnor = ~( A ^B);
endmodule
8 : 3 ENCOUNTER WITHOUT PRIORITY
VERILOG CODE:
module ENC83(I, Y);
input [7:0] I;
output [2:0] Y;
reg [2:0]Y;
always@ (I)
begin
case(I)
8'b00000001: Y =3'b000;
8'b00000010: Y =3'b001;
8'b00000100: Y =3'b010;
8'b00001000: Y =3'b011;
8'b00010000: Y =3'b100;
8
HDL integrated lab-21EC501-2024 Page 10
8'b00100000: Y =3'b101;
8'b01000000: Y =3'b110;
8'b10000000: Y =3'b111;
default: Y = 3'b ZZZ;
endcase
end
endmodule
8 : 3 ENCOUNTER WITH PRIORITY
VERILOG CODE:
Module penc83(d, b);
input [7:0] d;
output [2:0] b;
reg [2:0] b;
always@ (d)
begin
casex(d)
8'b00000001 : b =3'd0;
8'b0000001x : b =3'd1;
8'b000001xx : b = 3'd2;
8'b00001xxx : b = 3'd3;
8'b0001xxxx : b = 3'd4;
8'b001xxxxx : b = 3'd5;
8'b01xxxxxx : b = 3'd6;
8'b1xxxxxxx : b = 3'd7;
default: b = 3'dZ;
endcase
end
endmodule
2:4 DECODER
module decoder24(I,Y);
input [1:0]I;
output [3:0]Y;
reg [3:0]Y;
always@(I)
begin
case (I)
2'b 00 : Y = 4'b 0001;
2'b 01 : Y= 4'b 0010;
2'b 10 : Y = 4'b0100;
2'b 11 : Y = 4'b1000;
endcase
end
endmodule
8:1 MULTIPLEXER
module mux81(i, sel, y);
input [7:0] i;
input [2:0] sel;
output y;
reg y;
always @ ( sel or i )
begin
case (sel)
3' b 000: y = i[0];
3' b 001: y = i[1];
3' b 010: y = i[2];
3' b 011: y = i[3];
3' b 100: y = i[4];
3' b 101: y = i[5];
3' b 110: y = i[6];
3' b 111: y = i[7];
endcase
end
endmodule
1:4 DEMUX
module Demux14(i, s, y);
input i;
input [1:0] s;
output [3:0] y;
reg [3:0]y;
always@ (s)
begin
y = 4'b0000;
case (s)
2'b00:y[0] =i;
2'b01:y[1] =i;
2'b10:y[2] =i;
2'b11:y[3] =i;
endcase
end
endmodule
Binary to Gray code conversion
Module B2G(B, G);
input [3:0]B;
output [3:0]G;
assign G[3] = B[3];
assign G[2] =B[2]^B[3];
assign G[1] =B[2]^B[1];
assign G[0] = B[1]^B[0];
endmodule
Gray to Binary code conversion
Module G2B(B, G);
input [3:0]G;
output [3:0]B;
assign B[3] = G[3];
assign B[2] =G[2]^G[3];
assign B[1] =B[2]^G[1];
assign B[0] = B[1]^G[0];
endmodule
4 BIT COMPARATOR
module comp4(a, b, equ, less, grt);
input [3:0]a,b;
output equ,less,grt;
reg less,equ,grt;
always @(a,b)
begin
less = 0;
equ = 0;
grt = 0;
if (a<b)
less = 1 ;
HDL integrated lab-21EC501-2024 Page 19
else if (a == b)
equ = 1 ;
else if (a > b)
grt = 1;
end
endmodule
Half Adder
Behavioural modelling
module HA(a,b,sum,cout);
input a,b;
output sum,cout;
always@(a,b)
begin
sum = a^b;
cout = a & b;
end
endmodule
Data Flow modelling module HA(a,b,sum,cout);
input a,b;
output sum,cout;
sum = a^b;
cout = a & b;
endmodule
Full adder
Behavioural modelling module FA(a,b,cin,sum,cout);
input a,b,cin;
output sum,cout;
always@(a,b,cin)
begin
sum = a^b^cin;
cout = (a & b) ^ (b&cin) ^ (a&cin);
end
endmodule
Data Flow modelling module HA(a,b,cin,sum,cout);
input a,b,cin;
output sum,cout;
assign sum = a^b^cin;
assign cout = (a & b) ^ (b&cin) ^ (a&cin);
endmodule
HALF SUB
Data Flow
Module hs (a,b,d,br);
Input a,b;
Output d,br;
Assign d=a^b;
Assign br=~a&b;
endmodule
Behavioral
Module hs (a,b,d,br); Input a,b;
Output d,dr;
reg d,br;
Always @(a,b)
begin
d=a^b;
br=~a & b;
end
endmodule
Full subtractor
Dataflow model
Module fs(a,b,c,d,br);
Input a,b,c;
Output d,br;
assign d=a^b^c;
assign br=(~a&c)|(~a&b)|(b&c);
endmodule
Behavioral
Module fs(a,b,c,d,br);
Input a,b,c;
Output d,br;
Reg d,br; always @(a,b,c)
Begin d=a^b^c; br=(~a&c)|(~a&b)|(b&c);
end
endmodule
