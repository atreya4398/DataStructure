#include<stdio.h>


int stack[100],top=-1,sz;
int isFull();
int IsEmpty();
void push(char);
int pop();
int priority(char);

int main()
{
    printf("Enter the size : ");
    scanf("%d",&sz);

    char infixfix[100],infx,popval;
    int i;

    printf("Enter the Expression: ");
    scanf("%s",infixfix);

    for(i=0;infixfix[i]!='\0';i++)
    {
        infx=infixfix[i];
        if(isalnum(infx))
        {
            printf(" %c", infx);
        }
        else if(infx=='(')
        {
            push('(');
        }
        else if(infx==')')
        {
            while((popval=pop())!='(')
            {
                printf(" %c", pop());
            }
        }
        else
        {
            while(top!=-1&&priority(stack[top]) >= priority(infx))
            {
                printf(" %c", pop());
            }
            push(infx);
        }

    }

    while(top!=-1)
    {
        printf(" %c", pop());
    }
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
void push(char val)
{
    if(isFull()==1)
        printf("\nStack overflow !");
    else
    {
        top++;
        stack[top]=val;
       // printf("\nInserted successfully : %c", stack[top]);
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
       // printf("\nremoved element : %c", stack[top]);
        top--;
    }
    return(data);
}
int priority(char ch)
{
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='/'||ch=='*'||ch=='%')
        return 2;
    else if(ch=='^')
        return 3;
    else if(ch=='(')
        return 0;
    else
        return -1;
}
