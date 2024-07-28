LINEAR CONVOLUTION
clc ;
clear;
close;
x = input ( 'Enter Input Sequence=');
m = length ( x ) ;
Lx = input ( 'Enter Lower Index of Input Sequence=');
hx = Lx +m -1;
n = Lx :1: hx ;
h = input ( 'Enter Impulse Response Sequence=');
L = length ( h ) ;
Lh = input ( 'Enter Lower Index of Impulse Response Sequence=');
hh = Lh +L -1;
g = Lh :1: hh ;
nx = Lx + Lh ;
nh = nx + m +L -2;
y = convol (x , h )
disp(y);
r = nx : nh ;
subplot (3 ,1 ,1)
plot2d3 (n , x)
xlabel ( 'n' )
ylabel ( ' Amplitude' )
title ( ' Input Sequence x[ n ] ' )
subplot (3 ,1 ,2)
plot2d3 (g , h)
xlabel ( ' n' )
ylabel ( ' Amplitude' );
title ( 'Impulse Response Sequence h [n]' );
subplot (3 ,1 ,3);
plot2d3 (r , y);
xlabel ( ' n' );
ylabel ( ' Amplitude' );
title ('Output Response y [ n]');

VERIFY SAMPLING THEOREM
clc ;
close ;
clear ;
fm= input ( ' Enter the input signal frequency : ' );
k= input ( ' Enter the number of Cycles of input signal :' );
A= input ( ' Enter the amplitude of input signal : ' );
tm =0:1/( fm*fm):k/fm;
x=A*cos (2* %pi *fm*tm);
figure (1);
plot (tm ,x);
title ( 'ORIGINAL SIGNAL ' );
xlabel ( 'Time ' )
ylabel ( ' Amplitude ' );
xgrid(1)
// UNDER SAMPLING
fs1 = 1.5* fm;
n =0:1/ fs1:k/fm;
xn=A* cos (2* %pi*fm*n);
figure (2);
subplot(3,1,1);
plot2d3 (n,xn);
plot(n,xn,'r');
title ( ' Under Sampl ing ' );
xlabel ( 'Time ' );
ylabel ( ' Amplitude ' );
legend ( ' Sampled S i g n a l ' , ' Re c on s t r u c t e d S i g n a l ' );
xgrid(1)
//NYQUIST SAMPLING
fs2= 2 * fm;
n =0:1/ fs2:k/fm;
xn=A* cos (2* %pi *fm*n);
figure (2);
subplot(3,1,2);
plot2d3 (n,xn);
plot(n,xn,'r');
title ( ' Nyqui s t Sampl ing ' );
xlabel ( 'Time ' );
ylabel ( ' Ampl i tude ' );
legend ( ' Sampled S i g n a l ' , ' Re c on s t r u c t e d S i g n a l ' );
xgrid(1)
//OVER SAMPLING
fs3= 5 * fm;
n =0:1/ fs3:k/fm;
xn=A* cos (2* %pi *fm*n);
figure (2);
subplot(3,1,3);
plot2d3 ( n,xn);
plot (n,xn,'r');
title ( 'Over Sampl ing ' );
xlabel ( 'Time ' );
ylabel ( ' Ampl i tude ' );
legend ( ' Sampled S i g n a l ' , ' Re c on s t r u c t e d S i g n a l ' );
xgrid(1)

4 POINT AND 8 POINT DFT AND IDFT

DFT
clc;
close;
clear;
xn = input('Enter the real input discrete sequence x[ n]=');
N = length (xn);
XK = zeros (1,N);
//Code block to find the DFT of the Sequence
for K = 0:N -1
 for n = 0:N -1
 XK(K+1) = XK(K+1)+xn(n +1) exp(-%i *2 %pi*K*n/N);
 end;
end;
disp('Discrete Fourier Transform X( k )=');
disp(XK);
[phase ,db] = phasemag (XK);
disp('Magnitude Spectral Samples=');
disp (abs(XK));
disp('Phase Spectral Samples=');
disp (phase);
n = 0:N -1;
K = 0:N -1;
subplot(3,1,1);
plot2d3 (n,xn);
xlabel('Time Index n');
ylabel(' Amplitude');
title('Discrete Input Sequence');
subplot(3,1,2);
plot2d3(K,abs(XK));
xlabel('Frequency Sample Index>');
ylabel('|X(K)|');
title('Magnitude Spectrum');
subplot(3,1,3);
plot2d3(K,phase);
xlabel('Frequency Sample Index K');
ylabel('<X(K)');
title('Phase Spectrum');

IDFT

clc;
close;
clear;
Xk=[2+0*%i 1+%i 0+0*%i 1-%i];
N=length(Xk);
xn=zeros(1,N);
for n = 0:N -1
 for K = 0:N -1
 xn(n +1) = xn(n +1) + (Xk(K +1) * exp (%i 2 %pi *K*n/N)/N);
 end;
end;
ixn=real(xn);
disp('IDFT Sequence');
disp(ixn);
plot2d3([0:N-1],ixn);
xlabel('n');
ylabel('Amplitude x[n]');
title('IDFT Sequence ');

DFT USING FFT

clc;
close;
clear;
xn = input('Enter the real input discrete sequence x[n]=');
N = length (xn);
XK = zeros (1,N);
//Code block to find the FFT of the Sequence
XK= fft(xn);
disp('Discrete Fourier Transform X( k )=');
disp(XK);
[phase ,db] = phasemag (XK);
disp('Magnitude Spectral Samples=');
disp (abs(XK));
disp('Phase Spectral Samples=');
disp (phase);
n = 0:N -1;
K = 0:N -1;
subplot(3,1,1);
plot2d3 (n,xn);
xlabel('Time Index n');
ylabel(' Amplitude');
title('Discrete Input Sequence');
subplot(3,1,2);
plot2d3(K,abs(XK));
xlabel('Frequency Sample Index>');
ylabel('|X(K)|');
title('Magnitude Spectrum');
subplot(3,1,3);
plot2d3(K,phase);
xlabel('Frequency Sample Index K');
ylabel('<X(K)');
title('Phase Spectrum');

IDFT USING IFFT

clc;
close;
clear;
Xk=[2+0*%i 1+%i 0+0*%i 1-%i];
N=length(Xk);
xn=zeros(1,N);
xn = ifft(Xk)
ixn=real(xn);
disp('IDFT Sequence');
disp(ixn);
plot2d3([0:N-1],ixn);
xlabel('n');
ylabel('Amplitude x[n]');
title('IDFT Sequence ');

CIRCULAR CONVO

clc;
clear;
close;
x=[1 2 3 4];
h=[1 2 1 2];
N1 = length (x);
N2 = length (h);
N=max(N1,N2);
hn=[h,zeros(1,N-N2)];// Padding zeros to Make Length of 'h and 'x'
xn=[x,zeros(1,N-N1)];// Equal to length of output response y'
x1=xn;
h1=hn;
Y(1)=sum(x1.*h1); 
x2=[x1($)x1(1:$-1)];
Y(2)=sum(x2.*h1);
x3=[x2($)x2(1:$-1)];
Y(3)=sum(x3.*h1);
x4=[x3($)x3(1:$-1)];
Y(4)=sum(x4.*h1);
disp('Circular Convoluted Output y[n]',Y);
n=0:N-1;
subplot(3,1,1);
plot2d3(n,x1);
xlabel('n');
ylabel('Amplitude');
title('First Sequence x[n]');
subplot(3,1,2);
plot2d3(n,h1);
xlabel('n');
ylabel('Amplitude');
title('Second Sequence h[n]');
subplot(3,1,3);
plot2d3(n,Y);
xlabel('n');
ylabel('Amplitude');
title ('Circular Convoluted Output y[n]');

LINEAR USING CIRCULAR

clc;
clear;
close;
x=[1 2 2 1];// Input Response of LTI System
h=[1 2 3]; // Impulse Response of LTI System
N1 = length (x);
N2 = length (h);
N= N1+N2-1;
disp('Length of Output Sequence');
disp(N);
h1=[h,zeros(1,N-N2)];// Padding zeros to Make Length of 'h and 'x'
x1=[x,zeros(1,N-N1)];// Equal to length of output response y'
H=fft(h1);
X=fft(x1);
Y = X.*H; // Multiplication of 2 DFTs
yn= ifft(Y);
disp('Linear Convoluted Output');
disp(yn);
n=0:length(x)-1;
subplot(3,1,2);
plot2d3(n,x);
xlabel(' n');
ylabel('Amplitude');
title('Input Sequence x[n]');
g=0:length(h)-1;
subplot(3,1,1);
plot2d3(g,h);
xlabel('n');
ylabel('Amplitude');
title('Impulse Response Sequence h[n]');
r=0:length(yn)-1;
subplot(3,1,3);
plot2d3(r,yn);
xlabel('n');
ylabel('Amplitude');
title('Output Response y[ n]');

CROSS USING XCORR AND CONVOL

XCORRR

clc ;
clear ;
close ;
x = input ('Enter the First input Sequence');// x=[1 2 1 1]
y = input ('Enter the second input Sequence'); // y=[1 1 2 1]
mx = length(x);
my = length(y);
Lx = input ('Enter the lower index of first input sequence');// 0
Ly = input('Enter the lower index of second input sequence');// 0
hx = Lx+mx -1;
n = Lx :1: hx;
nx = Lx+Ly;
ny = nx+mx+my -2;
r = nx:ny;
Rxy = xcorr(x,y);
disp(' Cross Correlation Rxy[n]');
disp (Rxy);
subplot(3,1,1);
plot2d3(n,x);
xlabel('n');
ylabel('Amplitude');
title('Input Sequence x[n]');
subplot(3,1,2);
plot2d3(n,y);
xlabel('n');
ylabel('Amplitude');
title('Input Sequence y[n]');
subplot(3,1,3);
plot2d3(r,Rxy);
xlabel(' n');
ylabel('Amplitude');
title('Cross correlation Sequence Rxy[n]');

CONVOL
clc ;
clear ;
close ;
x = input ('Enter the First input Sequence');// x=[1 2 1 1]
y = input ('Enter the second input Sequence'); // y=[1 1 2 1]
mx = length(x);
my = length(y);
Lx = input ('Enter the lower index of first input sequence');// 0
Ly = input('Enter the lower index of second input sequence');// 0
hx = Lx+mx -1;
n = Lx :1: hx;
x_fold = x($ : -1:1) ;
y_fold = y($ : -1:1) ;
nx = Lx+Ly;
ny = nx+mx+my -2;
r = nx:ny;
Rxy = convol(x,y_fold);
Ryx = convol(x_fold,y);
disp(' Cross Correlation Rxy[n]');
disp (Rxy);
disp(' Cross Correlation Ryx[n]');
disp (Ryx);
subplot(3,1,1);
plot2d3(n,x);
xlabel('n');
ylabel('Amplitude');
title('Input Sequence x[n]');
subplot(3,1,2);
plot2d3(n,y);
xlabel('n');
ylabel('Amplitude');
title('Input Sequence y[n]');
subplot(3,1,3);
plot2d3(r,Rxy);
xlabel(' n');
ylabel('Amplitude');
title('Cross correlation Sequence Rxy[n]');
//Cross correlation of a sequence has Antisymmetry
disp('Cross Correlation has AntiSymmetry : Rxy[n]=Ryx[n]');

AUTO CORRE

XCORRR

clc;
clear;
close;
x=input('Enter the input Sequence');// x=[2 -1 3 4 1]
m=length(x);
Lx=input('Enter the lower index of input sequence:=');// -2
hx = Lx+m -1;
n = Lx :1: hx;
x_fold = x($ : -1:1) ;
nx = Lx+Lx;
nh = nx+m+m -2;
r = nx:nh;
Rxx=xcorr(x);
disp('Auto Correlation Rxx[n]');
disp(Rxx);
subplot(2,1,1);
plot2d3(n,x);
xlabel('n');
ylabel('Amplitude');
title('Input Sequence x[n]');
subplot(2,1,2);
plot2d3(r,Rxx);
xlabel(' n');
ylabel('Amplitude');
title('Auto correlation Sequence Rxx[n]');

CONVOL

clc;
clear;
close;
x=input('Enter the input Sequence');// x=[2 -1 3 4 1]
m=length(x);
Lx=input('Enter the lower index of input sequence:=');// -2
hx = Lx+m -1;
n = Lx :1: hx;
x_fold = x($ : -1:1) ;
nx = Lx+Lx;
nh = nx+m+m -2;
r = nx:nh;
Rxx=convol(x,x_fold);
disp('Auto Correlation Rxx[n]');
disp(Rxx);
subplot(2,1,1);
plot2d3(n,x);
xlabel('n');
ylabel('Amplitude');
title('Input Sequence x[n]');
subplot(2,1,2);
plot2d3(r,Rxx);
xlabel(' n');
ylabel('Amplitude');
title('Auto correlation Sequence Rxx[n]');
//'Auto Correlation has Even Symmetry
Rxx_flip=Rxx ([$ : -1:1]);
if Rxx_flip == Rxx ([$ : -1:1]);
 then
 disp('Auto Correlation has Even Symmetry');
 disp(Rxx_flip);
end

OVERLAP ADD

clc ;
clear ;
x = [1 2 3 4 5 2 4 0 1];
h = [1 1 1];
N1 = length(x);
N2 = length(h);
N = N1 + N2 -1;
y = zeros(1,N);
h1 = [h zeros(1,N2 -1)];
N3 = length(h1);
H = fft (h1) ;
for i = 1: N2 : N1
if i <=( N1 + N2 -1)
x1 = [x(i:i+N3-N2) zeros(1,N3-N2)];
else
x1 = [ x( i:N1) zeros(1,N3-N2)];
end
x2 = fft( x1);
x3 = x2 .* H ;
x4 = round (ifft(x3));
if ( i ==1)
y (1: N3 ) = x4 (1: N3 );
else
y ( i : i +N3 -1) = y ( i : i+ N3 -1) + x4 (1: N3 ) ;
end
end
subplot (3 ,1 ,1) ;
plot2d3 (x);
title ( 'Input Sequence x(n)');
xlabel ( 'Time') ;
ylabel ( 'Amplitude') ;
subplot (3 ,1 ,2) ;
plot2d3 ( h);
title ( 'InputSequence h(n)') ;
xlabel ( 'Time' ) ;
ylabel ( 'Amplitude ' ) ;
subplot (3 ,1 ,3) ;
disp ( 'Fast Convolution Using Overlap Add Method');
disp ( y (1: N ) ) ;
plot2d3 ( y (1: N ) ) ;
title ( 'Fast Convolution Using Overlap Add Method ') ;
xlabel ( 'Time') ;
ylabel ('Amplitude' ) ;

SAVE

clc ;
clear all;
x =[1 2 3 4 5 2 4 0 1];
h =[1 1 1];
N1 = length(x);
N2 = length(h);
N = N1 + N2 -1;
h1= [h zeros(1,N- N1)];
N3 = length(h1);
y = zeros (1,N ) ;
x1 =[zeros(1,N3-N2) x zeros(1,N3)];
H = fft (h1);
for i = 1: N2 : N
y1 = x1 ( i : i +(2*(N3-N2))) ;
y2 = fft( y1 ) ;
y3 = y2 .* H ;
y4 = round (ifft(y3));
y ( i :( i + N3 - N2 ) ) = y4 ( N2 : N3 ) ;
end
subplot (3,1,1) ;
plot2d3 (x) ;
title ('Input Sequence x(n)');
xlabel ('Time' ) ;
ylabel ('Amplitude' ) ;
subplot (3,1,2) ;
plot2d3 (h);
title ('Input Sequence h( n )');
xlabel ('Time');
ylabel ('Amplitude');
subplot (3,1,3) ;
disp ('Fast Convolution Using Overlap Save Method');
disp (y(1:N)) ;
plot2d3 (y(1:N)) ;
title ('Block Convolution Using Overlap Save Method');
xlabel ('Time');
ylabel ('Amplitude');

RECTANGULAR 

clc;
clear;
close;
fc=input('Enter Analog cutoff freq in Hz=');
fs=input('Enter Analog sampling freq in Hz=')
wp=input('Enter the pass band edge (rad )='); // 0.3 %pi ∗
ws=input('Enter the stop band edge (rad )='); // 0.45 %pi ∗
ks=input ('Enter the stop band attenuation (dB)=');// 0.5
w =(2*%pi)*(fc/fs);
// To select N, order of filter 
N=(2*%pi*4)./(ws-wp); // k=4 for Hamming window .
//N=ceil(N); //To round−off N to the next integer .
N=4;
//wc=(wp+(ws-wp)/2)./%pi
wc = w/%pi ;
// To obtain FIR filter Impulse Response 'wft'
//And FIR Filter Frequency response 'wfm'
[wft,wfm,fr]= wfir('lp',N +1,[wc/2,0],'re',[0,0]);
subplot(2,2,1);
plot(2*fr,20*log10(wfm),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Frequency Response in dB H(jw )=');
title('Frequency Response of FIR LPF');
xgrid(1)
subplot(2,2,2);
[wft,wfm1,fr]= wfir('hp',N +1,[wc/2,0],'re',[0,0]);
plot(2*fr,20*log10(wfm1),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Frequency Response in dB H(jw )=');
title('Frequency Response of FIR LPF');
xgrid(2)
//wc1 = 0.5*%pi //w1/%pi ;
//wc2 = 0.6*%pi //w2/%pi ;
w1=(2*%pi)*(500/fs);
w2=(2*%pi)*(600/fs);
wc1=w1/%pi;
wc2=w2/%pi;
[wft,wfm2,fr]=wfir('bp',N+1,[wc1/2,wc2/2],'re',[0,0]);
subplot(2,2,3);
plot(2*fr,20*log10(wfm2),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Frequency Response in dB H(jw )=');
title('Frequency Response of FIR LPF');
xgrid(3)
[wft,wfm3,fr]=wfir( 'sb',N+1,[wc1/2,wc2/2],'re',[0,0]);
subplot(2,2,4);
plot(2*fr,20*log10(wfm3),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Frequency Response in dB H(jw )=');
title('Frequency Response of FIR LPF');
xgrid(4)

KAISER

clc;
clear;
close;
wp=input('Enter the pass band edge (rad )='); // 0.3 %pi ∗
ws=input('Enter the stop band edge (rad )='); // 0.45 %pi ∗
ks=input ('Enter the stop band attenuation (dB)=');
//To select N, order of filter 
N=(2*%pi*4)./(ws-wp); // k=4 for Hamming window .
N=ceil(N); //To round−off N to the next integer .
wc=(wp+(ws-wp)/2)./%pi
// To obtain FIR filter Impulse Response 'wft'
//And FIR Filter Frequency response 'wfm'
[wft,wfm,fr]= wfir('lp' ,N +1,[wc/2,0],'kr',[0,0]);
plot(2*fr,20*log10(wfm),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Frequency Response in dB H(jw )=');
title('Frequency Response of FIR LPF');
xgrid (1)

HAMMING

clc;
clear;
close;
wp=input('Enter the pass band edge (rad )='); // 0.3 %pi ∗
ws=input('Enter the stop band edge (rad )='); // 0.45 %pi ∗
ks=input ('Enter the stop band attenuation (dB)=');
//To select N, order of filter 
N=(2*%pi*4)./(ws-wp); // k=4 for Hamming window
N=ceil(N); //To round−off N to the next integer
wc=(wp+(ws-wp)/2)./%pi
// To obtain FIR filter Impulse Response 'wft'
//And FIR Filter Frequency response 'wfm'
[wft,wfm,fr]= wfir('lp' ,N +1,[wc/2,0],'hm',[0,0]);
plot(2*fr,20*log10(wfm),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Frequency Response in dB H(jw )=');
title('Frequency Response of FIR LPF');
xgrid (1)

HANNING

clc;
clear;
close;
wp=input('Enter the pass band edge (rad )='); // 0.3 %pi ∗
ws=input('Enter the stop band edge (rad )='); // 0.45 %pi ∗
ks=input ('Enter the stop band attenuation (dB)=');
//To select N, order of filter 
N=(2*%pi*4)./(ws-wp); // k=4 for Hamming window
N=ceil(N); //To round−off N to the next integer
wc=(wp+(ws-wp)/2)./%pi
// To obtain FIR filter Impulse Response 'wft'
//And FIR Filter Frequency response 'wfm'
[wft,wfm,fr]= wfir('lp' ,N +1,[wc/2,0],'hn',[0,0]);
plot(2*fr,20*log10(wfm),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Frequency Response in dB H(jw )=');
title('Frequency Response of FIR LPF');
xgrid (1)

BUTTERWORTH
clc;
clear;
close;
fc=input('Enter Analog cutoff freq in Hz=');//250
fs=input('Enter Analog sampling freq in Hz=');//2000
N=input('Enter the Order of the filter=');//3
wc =2*fc/fs; //Pass band edge frequency 
//Generating low pass Butterworth IIR filter
[Hz1]=iir(N,'lp','butt',[wc/2,0],[0,0]);
[Hw1,w1]=frmag(Hz1,256); // The number of points in frequency response = 256
subplot(2,2,1);
plot(2*w1,abs(Hw1),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Butterworth low pass IIR filter ');
xgrid(1);
//Generating high pass Butterworth IIR filter
[Hz2]=iir(N,'hp','butt',[wc/2,0],[0,0]);
[Hw2,w1]=frmag(Hz2,256);
subplot(2,2,2);
plot(2*w1,abs(Hw2),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Butterworth high pass IIR filter ');
xgrid(1);
//Generating band pass Butterworth IIR filter
wc1 =2*400/fs;// Pass band edge frequency 1 
wc2 =2*600/fs;//Pass band edge frequency 2
[Hz3]=iir(N,'bp','butt',[wc1/2,wc2/2],[0,0]);
[Hw3,w1]=frmag(Hz3,256);
subplot(2,2,3);
plot(2*w1,abs(Hw3),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Butterworth band pass IIR filter ');
xgrid(1);
//Generating band stop Butterworth IIR filter
[Hz4]=iir(N,'sb','butt',[wc1/2,wc2/2],[0,0]);
[Hw4,w1]=frmag(Hz4,256);
subplot(2,2,4);
plot(2*w1,abs(Hw4),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Butterworth band stop IIR filter ');
xgrid(1);

chebychev 1
clc;
clear;
close;
fc=input('Enter Analog cutoff freq in Hz=');//250
fs=input('Enter Analog sampling freq in Hz=');//2000
N=input('Enter the Order of the filter=');//3
wc =2*fc/fs; //Pass band edge frequency 
//Generating low pass Chebyshev I IIR filter
[Hz1]=iir(N,'lp','cheb1',[wc/2,0],[0.1,0]);
[Hw1,w1]=frmag(Hz1,256);
subplot(2,2,1);
plot(2*w1,abs(Hw1),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev I low pass IIR filter ');
xgrid(1);
//Generating high pass Chebyshev I IIR filter
[Hz2]=iir(N,'hp','cheb1',[wc/2,0],[0.1,0]);
[Hw2,w1]=frmag(Hz2,256);
subplot(2,2,2);
plot(2*w1,abs(Hw2),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev I high pass IIR filter ');
xgrid(1);
//Generating band pass Chebyshev I IIR filter
wc1 =2*400/fs;// Pass band edge frequency 1 
wc2 =2*600/fs;//Pass band edge frequency 2
[Hz3]=iir(N,'bp','cheb1',[wc1/2,wc2/2],[0.1,0]);
[Hw3,w1]=frmag(Hz3,256);
subplot(2,2,3);
plot(2*w1,abs(Hw3),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev I band pass IIR filter ');
xgrid(1);
//Generating band stop Chebyshev I IIR filter
[Hz4]=iir(N,'sb','cheb1',[wc1/2,wc2/2],[0.1,0]);
[Hw4,w1]=frmag(Hz4,256);
subplot(2,2,4);
plot(2*w1,abs(Hw4),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev I band stop IIR filter ');
xgrid(1);

chebyshev 2

clc;
clear;
close;
fc=input('Enter Analog cutoff freq in Hz=');//250
fs=input('Enter Analog sampling freq in Hz=');//2000
N=input('Enter the Order of the filter=');//3
wc =2*fc/fs; //Pass band edge frequency 
//Generating low pass Chebyshev II IIR filter
[Hz1]=iir(N,'lp','cheb2',[wc/2,0],[0,0.1]);
[Hw1,w1]=frmag(Hz1,256);
subplot(2,2,1);
plot(2*w1,abs(Hw1),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev II low pass IIR filter ');
xgrid(1);
//Generating high pass Chebyshev II IIR filter
[Hz2]=iir(N,'hp','cheb2',[wc/2,0],[0,0.1]);
[Hw2,w1]=frmag(Hz2,256);
subplot(2,2,2);
plot(2*w1,abs(Hw2),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev II high pass IIR filter ');
xgrid(1);
//Generating band pass Chebyshev II IIR filter
wc1 =2*400/fs;// Pass band edge frequency 1 
wc2 =2*600/fs;//Pass band edge frequency 2
[Hz3]=iir(N,'bp','cheb2',[wc1/2,wc2/2],[0,0.1]);
[Hw3,w1]=frmag(Hz3,256);
subplot(2,2,3);
plot(2*w1,abs(Hw3),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev II band pass IIR filter ');
xgrid(1);
//Generating band stop Chebyshev II IIR filter
[Hz4]=iir(N,'sb','cheb2',[wc1/2,wc2/2],[0,0.1]);
[Hw4,w1]=frmag(Hz4,256);
subplot(2,2,4);
plot(2*w1,abs(Hw4),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Chebyshev II band stop IIR filter ');
xgrid(1);

eleptical

clc;
clear;
close;
fc=input('Enter Analog cutoff freq in Hz=');//250
fs=input('Enter Analog sampling freq in Hz=');//2000
N=input('Enter the Order of the filter=');//3
wc =2*fc/fs; //Pass band edge frequency 
//Generating low pass Elliptic IIR filter
[Hz1]=iir(N,'lp','ellip',[wc/2,0],[0.1,0.1]);
[Hw1,w1]=frmag(Hz1,256);
subplot(2,2,1);
plot(2*w1,abs(Hw1),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Elliptic low pass IIR filter ');
xgrid(1);
//Generating high pass Elliptic IIR filter
[Hz2]=iir(N,'hp','ellip',[wc/2,0],[0.1,0.1]);
[Hw2,w1]=frmag(Hz2,256);
subplot(2,2,2);
plot(2*w1,abs(Hw2),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Elliptic high pass IIR filter ');
xgrid(1);
//Generating band pass Elliptic IIIR filter
wc1 =2*400/fs;// Pass band edge frequency 1 
wc2 =2*600/fs;//Pass band edge frequency 2
[Hz3]=iir(N,'bp','ellip',[wc1/2,wc2/2],[0.1,0.1]);
[Hw3,w1]=frmag(Hz3,256);
subplot(2,2,3);
plot(2*w1,abs(Hw3),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Elliptic band pass IIR filter ');
xgrid(1);
//Generating band stop Elliptic IIR filter
[Hz4]=iir(N,'sb','ellip',[wc1/2,wc2/2],[0.1,0.1]);
[Hw4,w1]=frmag(Hz4,256);
subplot(2,2,4);
plot(2*w1,abs(Hw4),'r');
xlabel('Normalized Digital Frequency w');
ylabel('Magnitude');
title('Elliptic band stop IIR filter ');
xgrid(1);
