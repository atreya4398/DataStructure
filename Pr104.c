#include<stdio.h>

void calc(int ar[],int s,int x)
{
    int i,sum,pow;
    sum=ar[0];

    for(i=1;i<=s;i++)
    {
        sum=sum*x+ar[i];
    }

    printf("Sum of equation : %d\n",sum);

}
int main()
{
    int i,s,x,arr[100];

    printf("Enter order polynomial :");
    scanf("%d",&s);

    printf("Enter X: ");
    scanf("%d",&x);

    printf("Enter coefficients : ");
    for(i=1;i<=s;i++)
    {
        scanf("%d",&arr[i]);
    }

    calc(arr,s,x);
}
