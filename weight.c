#include<stdio.h>
void main()
{
    int i,n,f=0;
    float w[20], sw;

    printf("How many students weight you want to enter\n");
    scanf("%d",&n);

    printf("Enter %d students weights\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&w[i]);
    }

    printf("Enter students weight whom you want to search\n");
    scanf("%f",&sw);

    for(i=0;i<n;i++)
    {
        if(w[i]==sw)
        printf("Student found at %d position\n",i+1);
        f=1;
    }
    if(f==0)
    printf("No student found with this weight\n");
}