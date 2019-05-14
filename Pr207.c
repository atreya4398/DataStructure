#include<stdio.h>
#include<stdlib.h>
void rotatearr(int *ar,int s,int dd)
{
    int temp;
    int i,j;
    for(i=0;i<dd;i++)
    {
        temp=ar[0];
        for(j=0;j<s;j++)
        {
            ar[j]=ar[j+1];
        }
        ar[s-1]=temp;
    }
}
int main()
{
    int *arr,sz,d,i;

    printf("\nEnter the size: ");
    scanf("%d",&sz);

    arr=(int *)calloc(sz,sizeof(int));
    for(i=0;i<sz;i++)
    {
        printf("Enter elements %d:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter value of d for rotate: ");
    scanf("%d",&d);

    printf("\nArray before rotation:- ");
    for(i=0;i<sz;i++)
    {
        if(i<sz-1)
        {
            printf("%d , ",arr[i]);
        }
        else
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
    if(d>sz)
        printf("d is bigger than size !");
    else
    {
        rotatearr(arr,sz,d);
         printf("\nArray after rotation:- ");
        for(i=0;i<sz;i++)
        {
            if(i<sz-1)
            {
                printf("%d , ",arr[i]);
            }
            else
            {
                printf("%d ",arr[i]);
            }
        }
    }
}
