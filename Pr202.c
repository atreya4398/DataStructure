#include<stdio.h>
#include<stdlib.h>

int length(char *arr)
{
    int ctn=0,i;
    for(i=0;arr[i]!='\0';i++)
        ctn++;
    return ctn;
}

void strreplace(char main[],char *st,char sr[],char rp[])
{
    int i,flag=0,j,k=0;
    int indexarr[20];
    int cnt=0;
    int x,track=0;
    for(i=0;i<length(st);i++)
    {
        if(st[i]==sr[0])
        {
            k=i;
            flag=1;
            for(j=0;j<length(sr);j++)
            {
                if(st[k]!=sr[j])
                {
                    flag=0;
                    break;
                }
                else
                {
                    k++;
                }
            }
            if(flag)
            {
                indexarr[cnt++]=i+1;
                for(x=0;x<length(rp);x++)
                {
                    st[track++]=rp[x];
                }
                i=(i+length(sr))-1;
            }
            else
            {
                st[track++]=main[i];
            }
        }
        else
        {
            st[track++]=main[i];
        }
    }
    st[track]='\0';

    if(cnt!=0)
    {
        printf("Search string found on index : ");
        for(i=0;i<cnt;i++)
        {
            printf("%d ",indexarr[i]);
        }
    }
    else
    {
        printf("search string not found !");
    }
}
int main()
{
    char mainstr[100],search[50],replace[50],*arr;

    printf("Enter string from user: ");
    gets(mainstr);

    arr=(char *)calloc(length(main),sizeof(char));

    printf("Enter search string: ");
    scanf("%s",search);

    printf("Enter string to be replace: ");
    scanf("%s",replace);

    strreplace(mainstr,arr,search,replace);
}
