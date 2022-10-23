#include<stdio.h>
#include<string.h>
void main()
{
    char names [100][50],temp[50];
    int i,j,n;
    printf("How many students name you want to enter\n");
    scanf("%d",&n);
    fflush(stdin);
    printf("Enter %d students name\n",n);
    for(i=0;i<n;i++)
    scanf("%s",&(names[i]));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(strcmp(names[j],names[j+1])>0)
            {
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }
    printf("\n Students name in sorted order \n");
    for(i=0;i<n;i++)
    puts(names[i]);
}