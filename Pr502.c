#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* front;
struct node* rear;

void enqueue()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("\nEnter data: ");
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=NULL;

    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
        front->next=NULL;
        rear->next=NULL;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=NULL;
    }
    printf("\nINSERTED !");
}

void dequeue()
{
    struct node* temp;

    if(front==NULL)
        printf("\nunderflow!");
    else
    {
        temp=front;
        front=front->next;
        free(temp);
        printf("\n Deleted !");
    }
}

void display()
{
    struct node* temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
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
            enqueue();
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
