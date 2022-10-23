#include<stdio.h>
void main()
{
    int ll,ul,i,f;
    int prime(int);
    printf("Enter the range of numbers \n");
    printf("Lower limit:\n");
    scanf("%d",&ll);
    printf("Upper limit;\n");
    scanf("%d",&ul);
    printf("Prime numbers between %d and %d are \n",ll,ul);
    for(i=ll;i<=ul;i++)
    {
        if(prime(i))
        printf("%d\t",i);
    }
}
int prime (int num){
    int i;
    for(i=2;i<=num/2;i++)
    {
        if(num%i==0)
        return 0;
    }
    return 1;
}