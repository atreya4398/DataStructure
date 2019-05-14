#include<stdio.h>
#include<stdlib.h>

void newstr(char *strng,char c,int p)
{
    --p;
    int i;
    for(i=0;strng!='\0';i++)
    {
        if(i==p)
        {
            strng[i]=c;
            break;
        }
    }
    printf("\nNew string is : %s",strng);
}
int main()
{
    char *st,ch;
    int pos;

    st=(char *)calloc(20,sizeof(char));

    printf("Enter your string: ");
    scanf("%s",st);

    printf("\nEnter the character : ");
    scanf(" %c",&ch);

    printf("\nEnter the position: ");
    scanf("%d",&pos);

    newstr(st,ch,pos);

}
