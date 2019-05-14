#include<stdio.h>

int main()
{
    int i,arr[15],*p,elesz;

    for(i=0;i<15;i++)
    {
        printf("Element [%d]:",i+1);
        scanf("%d",&arr[i]);
    }
    p=&arr[0];

    elesz=sizeof(arr)/sizeof(arr[0]);
    printf("Element size: %d\n",elesz);

    for(i=0;i<15;i++)
    {
        printf("%d ",*p);
        p++;
    }


}
