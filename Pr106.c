#include<stdio.h>

int sort(int s[],int n);
int main()
{
    int ar[10],s,i;
    printf("enter size:");
    scanf("%d",&s);
    printf("enter array: ");
    for(i=0;i<s;i++)
    {
        scanf("%d",&ar[i]);
    }
    sort(ar,s);

}
int sort(int arr[],int m)
{
    int i,j,temp;
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(arr[i]>arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for(i=0;i<m;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
