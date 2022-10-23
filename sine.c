#include<stdio.h>
#include<math.h>
void main()
{
    int i, n, deg;
    float x , sum=0, term;

    printf("Enter the degree to find the sine value\n");
    scanf("%d",&deg);

    printf("Enter the number of terms in the series\n");
    scanf("%d",&n);

    x = 3.142/180*deg;
    term = x;

    for(i=1;i<=n;i++)
    {
        sum = sum + term;
        term*= -(x*x)/((2*i)*(2*i+1));
    }
    printf("sin(%d) = %f\n",deg,sum);
    printf("Using libraray function sin(%d) = %f",deg,sin(x));
}