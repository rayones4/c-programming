#include<stdio.h>
void main()
{
    int i, n, marks[25], sum=0, *p;
    float avg;
    printf("How many subject marks you want to enter \n");
    scanf("%d",&n);
    printf("Enter %d subject marks\n",n);
    for(i=0;i<n;i++)
    scanf("%d",&marks[i]);
    p=marks;
    for(i=0;i<n;i++)
    sum += *(p+i);
    avg = (float)sum/n;
    printf("Total:%d\n Avg:%.2f",sum,avg);
}