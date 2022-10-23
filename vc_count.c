#include<stdio.h>
void main()
{
    int vcount=0, ccount=0, i;
    char str[50];
    printf("Enter a string\n");
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(isalpha(str[i]))
        {
            switch (str[i])
            {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':vcount++;
                break;
            
            default:ccount++;
                
            }
        }
    }
    printf("Number of vowels are %d\n",vcount);
    printf("Number of consonants are %d\n",ccount);
}