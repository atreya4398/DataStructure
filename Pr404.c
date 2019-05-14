#include<stdio.h>
#include<string.h>

int stack[100],top=-1,sz;
int isFull();
int IsEmpty();
void push(char);
char pop();
int priority(char);
//char reversearr(char []);
int main()
{
    printf("Enter the size : ");
    scanf("%d",&sz);

    char infixfix[100],infx,popval,prefix[100];
    int i,j=0;

    printf("Enter the Expression: ");
    scanf("%s",infixfix);


    //strcpy(prefix,reversearr(infixfix));

//    printf("reverse string : %s",strrev(infixfix));
    for(i=0;infixfix[i]!='\0';i++)
    {
        infx=infixfix[i];
        if(isalnum(infx))
        {
            prefix[j++]=infx;
        }
        else if(infx==')')
        {
            push(')');
        }
        else if(infx=='(')
        {
            while((popval=pop())!=')')
            {
                prefix[j++]=pop();
            }
        }
        else
        {
            while(top!=-1&&priority(stack[top]) >= priority(infx))
            {
                prefix[j++]=pop();
            }
            push(infx);
        }

    }

    while(top!=-1)
    {
        prefix[j++]=pop();
    }
    prefix[j]='\0';


    printf("prefix expression : %s",strrev(prefix));
}

/*char reversearr(char infix[])
{
    int i,j;
    char pre[100];
    for(i=strlen(infix)-1;i>=0;i--)
    {
        pre[j++]=infix[i];
    }
    pre[j]='\0';
    return pre;
}*/

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
char pop()
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
