#include<stdio.h>
void swap(int*,int*);
void main()
{
    int i , j, n, a[25];
    printf("How many numbers you want to enter to sort\n");
    scanf("%d",&n);
    printf("Enter %d numbers\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
        }
    }
    printf("Given numbers in sorted order \n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
void swap(int*a,int*b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}