#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,c,disc;
    float r1,r2;

    printf("Enter non-zero co-efficients of a quadratic equation\n");
    scanf("%d%d%d",&a,&b,&c);

    disc = b*b - 4*a*c;

    if(a*b*c == 0)
    printf("Invalid input , try again\n");

    if(disc>0){
            printf("Roots are real and distinct\n");
    r1 = (-b + sqrt(disc))/(2.0*a);
    r2 = (-b - sqrt(disc))/(2.0*a);
    printf("Root 1 = %.2f\n Root 2 = %.2f\n",r1,r2);
    }
    else if(disc == 0)
    {
    printf("Roots are real and distinct\n");
    r1=r2= -b/(2.0*a);
    printf("Root 1 = %.2f\n Root 2 = %.2f\n",r1,r2);
    }
    else
    {
    printf("Roots are imaginary\n");
    r1 = -b/(2.0*a);
    r2 = sqrt(fabs(disc))/(2.0*a);
    printf("Root 1 = %.2f + i%.2f\n",r1,r2);
    printf("Root 2 = %.2f - i%.2f\n",r1,r2);
    }
}