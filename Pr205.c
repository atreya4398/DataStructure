#include<stdio.h>
#include<stdlib.h>

void strremove(char *arr)
{
    int len=0,i,cnt=0,j;
    char *st;
    for(i=0;arr[i]!='\0';i++)
        len++;
    st=(char *)calloc(len,sizeof(char));

    for(i=0;i<len;i++)
    {
        if(!((arr[i]>='a' && arr[i]<='z')||(arr[i]>='A' && arr[i]<='Z')))
        {
            st[cnt++]=arr[i];
            for(j=i;j<len-1;j++)
            {
                arr[j]=arr[j+1];
            }
            arr[--len]='\0';
            --i;
        }
    }

    if(cnt!=0)
    {
        printf("%d characters removed ",cnt);
        for(i=0;i<cnt;i++)
        {
            printf("%s ",st);
        }
        printf("\n");
    }
    else
    {
        printf("There are only alphabets and characters!");
    }


}
int main()
{
    char str[50],*arr;
    printf("Enter string: ");
    scanf("%s",str);

    arr=(char *)calloc(50,sizeof(char));

    strremove(str);
}
