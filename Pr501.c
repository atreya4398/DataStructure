#include<stdio.h>
#define SIZE 50

int queue[SIZE];
int front=-1,rear=-1;

int isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear==SIZE-1)
        return 1;
    else
        return 0;
}

void insert()
{
    int val;
    if(!isFull())
    {

            if(front==-1)
                front=0;

            printf("\nEnter value : ");
            scanf("%d",&val);
            rear++;
            queue[rear]=val;
             printf("\nINSERTED !\n");
    }
    else
    {
        printf("\nQueue is full !");
    }

}

void display()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}

void dequeue()
{
    if(!isEmpty())
    {
        printf("\nDeleted : %d",queue[front]);
        front++;

    }
    else
    {
        printf("\nQueue is empty !");
    }
}

int main()
{
    int choice;

    while(choice!=4)
    {
        printf("\n1.insert\n2.display\n3.Delete\n4.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            break;
        }
    }
}
