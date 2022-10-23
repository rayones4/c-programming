#include<stdio.h>
void main()
{
    int cnum, pow;
    float amt;

    printf("Enter the customer number and power consumed \n");
    scanf("%d%d",&cnum,&pow);

    if(pow<=200)
    amt = 0.50 * pow;
    else if(pow<=400)
    amt = 100 + (0.65*(pow-200));
    else if(pow<=600)
    amt = 230 + (0.80*(pow-400));
    else 
    amt = 390 +(1.00*(pow-600));
    printf("Customer has to pay %.2f",amt);
}