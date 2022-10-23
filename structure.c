#include <stdio.h>

void main()
{
struct student
{
char name[50],usn[10];
int cie1,cie2,cie3,act1,act2,total;
}s[10];
int i,n;

printf("How many students information you want to enter\n"); 
scanf("%d",&n);
for(i=0;i<n;i++)
{
getchar();
printf("\nEnter %d student details\n",i+1); 
printf("USN : ");
gets(s[i].usn);
printf("Name : ");
gets(s[i].name);
 printf("First CIE marks : ");
  scanf("%d",&s[i].cie1);
printf("Second CIE marks : "); 
scanf("%d",&s[i].cie2); 
printf("Third CIE marks : "); 
scanf("%d",&s[i].cie3); 
printf("Activity-1 marks : "); 
scanf("%d",&s[i].act1); 
printf("Activity-2 marks : "); 
scanf("%d",&s[i].act2);
if(s[i].cie1<s[i].cie2&&s[i].cie1<s[i].cie3)
s[i].total=s[i].cie2+s[i].cie3+s[i].act1+s[i].act2; 
else if(s[i].cie2<s[i].cie3)
s[i].total=s[i].cie1+s[i].cie3+s[i].act1+s[i].act2;
else
s[i].total=s[i].cie1+s[i].cie2+s[i].act1+s[i].act2;
}
printf("\nStudents information is as follows\n"); 
for(i=0;i<n;i++)
{
printf("\nUSN : %s\t\t\tName : %s\n",s[i].usn,s[i].name);
 
printf("CIE1\tCIE2\tCIE3\tAct-1\tAct-2\tTotal\n");
 printf(" %d\t %d\t %d\t %d\t %d\t %d\n",s[i].cie1,s[i].cie2,s[i].cie3,s[i].act1,s[i].act2,s[i].total);
}
}
