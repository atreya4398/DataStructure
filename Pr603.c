#include<stdio.h>
#include<stdlib.h>

struct Qnode
{
    int data;
    struct Qnode* next;
}*front=NULL,*rear=NULL;

void insert()
{
    struct Qnode* newnode=(struct Qnode*)malloc(sizeof(struct Qnode));
    int info;

    printf("\nEnter data: ");
    scanf("%d",&info);

    newnode->data=info;
    newnode->next=NULL;

    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("\n INSERTED !");
}

void removedata()
{
    if(front==NULL)
        printf("\nQueue is empty !");
    else
    {
        struct Qnode* temp;
        temp=front;

        front=front->next;

        printf("\n Deleted %d ",temp->data);
        free(temp);
    }
}

void display()
{
    struct Qnode* temp;
    temp=front;

    while(temp!=NULL)
    {
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice;

    while(choice!=4)
    {
        printf("\n1.insert \n2.remove\n3.display\n4.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            removedata();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        }
    }
}
