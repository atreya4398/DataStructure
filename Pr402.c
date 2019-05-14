#include<stdio.h>

int stack[100],top=-1,sz;
int isFull();
int IsEmpty();
void push(int);
int pop();
int main()
{
    printf("Enter the size : ");
    scanf("%d",&sz);

    char postfix[100],c;
    int i=0,e1,e2,r;

    printf("\nEnter the expression: ");
    scanf("%s",postfix);

    while(postfix[i]!='\0')
    {
       // printf("\nenter the value of  %c :", c);
       // scanf("%d",&x);
        c=postfix[i];
        if(isdigit(c))
        {
            push(c-'0');
        }

        switch(c)
        {
        case '+':
            e1=pop();
            e2=pop();
            r=e2+e1;
            push(r);
            break;
        case '-':
            e1=pop();
            e2=pop();
            r=e2-e1;
            push(r);
            break;
        case '*':
            e1=pop();
            e2=pop();
            r=e2*e1;
            push(r);
            break;
        case '/':
            e1=pop();
            e2=pop();
            r=e2/e1;
            push(r);
            break;

        }
        i++;
    }
    r=pop();
    printf("\nResult of expression : %d",r);
}

int isFull()
{
    if(top>=sz)
        return 1;
    else
        return 0;
}
int IsEmpty()
{
    if(top<0)
        return 1;
    else
        return 0;
}
void push(int val)
{
    if(isFull()==1)
        printf("\nStack overflow !");
    else
    {
        top++;
        stack[top]=val;
        printf("\nInserted successfully : %d",stack[top]);
    }
}
int pop()
{
    int data;
    if(IsEmpty()==1)
        printf("\nStack Underflow !");
    else
    {
        data=stack[top];
       // printf("\nremoved element : %d",stack[top]);
        top--;
    }
    return(data);
}
