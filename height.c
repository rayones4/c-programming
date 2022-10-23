#include<stdio.h>
void main()
{
    int h1,h2,h3;

    printf("Enter the height of three students\n");
    scanf("%d%d%d",&h1,&h2,&h3);

    if(h1>h2)
    {
        if(h1>h3)
        {
            printf("First person is tallest\n");
        }
        else{
            printf("Third person is tallest\n");
        }
    }
    else{
        if(h2>h3){
            printf("Second person is tallest\n");
        }
        else{
            printf("Third person is tallest\n");
        }
    }
}