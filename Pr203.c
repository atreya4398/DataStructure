#include<stdio.h>
#include<string.h>

void reverse(char st[])
{
    int i;
    char temp;
    int size=strlen(st);
    for(i=0;i<size/2;i++)
    {
        temp=st[i];
        st[i]=st[size-i-1];
        st[size-i-1]=temp;
    }
    printf("Reverse string is : %s",st);
}
int main()
{
    char str[50];

    printf("Enter string: ");
    scanf("%s",str);
    reverse(str);


}
