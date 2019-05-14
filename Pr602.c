#include<stdio.h>
#include<stdlib.h>

struct Stnode
{
    int data;
    struct Stnode* next;
}*top=NULL;

void insert()
{
    int info;
    struct Stnode* newnode=(struct Stnode*)malloc(sizeof(struct Stnode));
    printf("\nEnter data : ");
    scanf("%d",&info);

    newnode->data=info;
    newnode->next=NULL;

    newnode->next=top;
    top=newnode;

    printf("\nINSERTED !");
}

void pop()
{
    if(top==NULL)
        printf("\nStack is empty !");
    else
    {
        struct Stnode* temp;
        temp=top;

        printf("\nDeleted %d!",temp->data);
        top=temp->next;
        free(temp);
    }
}

void Display()
{
    struct Stnode* temp;

    temp=top;

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
        printf("\n1.Push\n2.Pop\n3.display\n4.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            break;
        }
    }
}
