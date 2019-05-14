#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void palindrome(char *arr)
{
    int i,flag=0,j=0;
    char str[20];
    for(i=strlen(arr)-1;i>=0;i--)
    {
        str[j++]=arr[i];
    }
    str[j]='\0';

    for(i=0;i<strlen(str);i++)
    {
       if(arr[i]!=str[i])
       {
           flag=1;
           break;
       }

    }

    if(flag==0)
        printf("Is palindrome");
    else
        printf("Is not palindrome");



}
int main()
{
    char str[50],*arr;
    arr=(char *)calloc(50,sizeof(char));
     printf("enter string: ");
    scanf("%s",arr);

   palindrome(arr);
}
