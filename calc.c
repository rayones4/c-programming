#include<stdio.h>
void main()
{
    int a,b;
    char op;
    
    printf("Enter any mathematical expression (eg: 2+4) \n");
    scanf("%d%c%d",&a,&op,&b);
    switch(op)
    {
        case '+' : printf("%d + %d = %d\n",a,b,a+b);
        break;
        case '-' : printf("%d - %d = %d\n",a,b,a-b);
        break;
        case '*': printf("%d * %d\n",a,b,a*b);
        break;
        case '/' : printf("This operation gives the quotient /n");
                  printf("%d / %d = %f\n", a,b,(float)a/b);
        break;
        case '%' : printf("This operation gives the remainder /n");
        printf("%d %% %d = %d\n",a,b,a%b);
        break;
        default : printf("Not a valid mathematical expression\n");
    }
    
}