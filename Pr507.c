#include<stdio.h>

int stack1[100],stack2[100];
int top1=-1;
int top2=-1;
int count=0;

void push1(int data)
{
    stack1[++top1]=data;
}

void push2(int data)
{
    stack2[++top2]=data;
}

int pop1()
{
    return(stack1[top1--]);
}

int pop2()
{
    return(stack2[top2--]);
}

void enqueue()
{
    int data;

    printf("\nEnter data : ");
    scanf("%d",&data);

    push1(data);
    count++;

    printf("\nINSERTED !");
}

void dequeue()
{
    int i;

    for(i=0;i<=count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;

    for(i=0;i<=count;i++)
    {
        push1(pop2());
    }

    printf("\nDeleted !");
}

int display()
{
    int i;

    for(i=0;i<=top1;i++)
    {
        printf("%d ",stack1[i]);
    }
}

void reverse_queue()
{
    int i;
    for(i=top1;i>=0;i--)
    {
        printf("%d ",stack1[i]);
    }
}

int main()
{
    int choice;

    while(choice!=5)
    {
        printf("\n1.insert\n2.display\n3.Delete\n4.reverse\n5.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            display();
            break;
       case 3:
            dequeue();
            break;
        case 4:
            reverse_queue();
            break;
        case 5:
            break;
        }
    }
}


