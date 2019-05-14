#include<stdio.h>

int sum(int ar[][20],int r,int c);
int main()
{
    int arr[10][20],i,j,s1,s2;
    printf("enter size1: ");
    scanf("%d",&s1);
    printf("enter size2: ");
    scanf("%d",&s2);

    printf("Enter array members:");
    for(i=0;i<s1;i++)
    {
        for(j=0;j<s2;j++)
        {
            printf("elements [%d][%d]:",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    sum(arr,s1,s2);

    return 0;
}
int sum(int ss[][20],int m,int n)
{
    int i,j,sum=0;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=ss[i][j];
        }
    }

   printf("sum is : %d",sum);
   return 0;
}
