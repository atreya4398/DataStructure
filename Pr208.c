#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *arr,i,sz,temp;

    printf("Enter size:");
    scanf("%d",&sz);

    arr=(int *)calloc(sz,sizeof(int));

    for(i=0;i<sz;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nArray before swapping : - ");
    for(i=0;i<sz;i++)
    {
        if(i<sz-1)
            printf("%d , ",arr[i]);
        else
            printf("%d ",arr[i]);
    }

    for(i=0;i<sz-1;i+=2)
    {
        if(i%2==0)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        else
        {
            if(arr[i]<arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }

    }

    printf("Array after swapping : - ");
    for(i=0;i<sz;i++)
    {
        if(i<sz-1)
            printf("%d , ",arr[i]);
        else
            printf("%d ",arr[i]);
    }

}
