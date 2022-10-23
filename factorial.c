#include<stdio.h>
long fact (int);
void main()
{
    int n, r;
    long ncr, npr;
    printf("Enter the value of n and r (n>r)\n");
    scanf("%d%d",&n,&r);
    ncr = fact(n)/ (fact(r)*fact(n-r));
    npr = fact(n)/fact(n-r);
    printf("nCr=%1d and nPr=%1d",ncr,npr);
}
long fact (int n)
{
    int i;
    long f =1;
    for(i=1;i<=n;i++)
    f = f*i;
    return f;
}