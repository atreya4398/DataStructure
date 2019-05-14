#include<stdio.h>
#include<stdlib.h>
int stack[100],top=-1,sz;

void push();
int Isfull();
int Isempty();
void pop();
void peep();
void update();
void display();
int main()
{
    printf("Enter size: ");
    scanf("%d",&sz);

    int choice;
    printf("1.Push\n2.Pop\n3.Peep\n4.Update\n5.Display\n6.Exit\n");

    while(choice!=6)
    {
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            update();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Opps! wrong choice ...");
        }
    }
}
int Isfull()
{
    if(top>=sz)
        return 1;
    else
        return 0;
}
int Isempty()
{
    if(top<0)
        return 1;
    else
        return 0;
}
void push()
{
    int data;

    if(Isfull()==1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        printf("Enter data you want to enter: ");
        scanf("%d",&data);
        top++;
        stack[top]=data;
    }
}
void pop()
{
    if(Isempty()==1)
    {
        printf("Stack Underflow !");
    }
    else
    {
        printf("Value removed from stack is : %d",stack[top]);
        top--;
    }
}
void peep()
{
    int ind;
    printf("Enter index number :");
    scanf("%d",&ind);
    if(top-ind==0)
    {
        printf("Stack overflow !");
    }
    else
    {
        printf("Element from top of the stack is : %d",stack[top-ind]);
    }
}
void update()
{
    int flag=0;
    int ind;
    int newdata;
    printf("Enter index for update: \n");
    scanf("%d",&ind);
    printf("Enter new data : \n");
    scanf("%d",&newdata);
    if(top-ind==0)
        printf("Stack overflow !\n");
    else
    {
        flag=1;
        stack[top-ind]=newdata;
        printf("updated successfully !\n");
    }
}
void display()
{
    int i;
    if(Isempty()==1)
        printf("Stack underflow !");
    else
    {
        for(i=top;i>=0;--i)
            printf("| %d |\n",stack[i]);
    }
}
