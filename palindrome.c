
#include<stdio.h>
void main()
{
    int num, rev=0, dig, x;

    printf("Enter the 4 digit registration number \n");
    scanf("%d",&num);

    x = num;

    while(num!=0)
    {
        dig = num % 10;
        rev = rev*10 + dig;
        num = num/10;
    }

    if(rev==x)
    {
        printf("The number is a palindrome\n");
    }
    else{
        printf("The number is not a paindrome\n");
    }
}