#include<stdio.h>

int swap(int,int,int *,int *);
int main()
{
    int n1,n2,n3,n4,*p1,*p2;
    printf("Enter four values: ");
    scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
    p1=&n3;
    p2=&n4;
    swap(n1,n2,&n3,&n4);
    return 0;
}
int swap(int a,int b,int *p1,int *p2)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
    printf(" swap %d %d",a,b);

    int t;
    t=p1;
    p1=p2;
    p2=t;
    printf(" swap %d %d",*p1,*p2);
    return 0;
}
