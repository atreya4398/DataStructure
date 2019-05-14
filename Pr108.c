#include<stdio.h>
#include<string.h>
int main()
{
    char str[10],rev[10],len,i,j,flag;
    printf("Enter string:");
    scanf("%s",str);
    len=strlen(str);
    for(i=len-1;i>=0;i--)
    {
        rev[j++]=str[i];
    }
    rev[j]='\0';

    for(i=0;i<len;i++)
    {
        if(str[i]==rev[i])
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("Palindrome");
    }
    else
    {
        printf("not palindrome");
    }
}
