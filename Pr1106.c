#include<stdio.h>
#include<stdlib.h>
struct llnode
{
    int data;
    struct llnode* next;
}*head=NULL;


void insertatB()
{
    int info;
    struct llnode *newnode=(struct llnode*)malloc(sizeof(struct llnode));

    if(newnode==NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter data:");
        scanf("%d",&info);
        newnode->data=info;
        newnode->next=head;
        head=newnode;
        printf("\nInserted!");
    }

}

void Display()
{
    struct llnode* tmp;
    tmp=head;

    if(tmp==NULL)
    {
        printf("List is empty !");
    }
    else
    {
        while(tmp!=NULL)
        {
            printf("%d --> ",tmp->data);
            tmp=tmp->next;
        }
    }

}

void bubblesort(struct llnode* temp)
{
    struct llnode* sortnode=NULL;
    struct llnode* store;
    store=temp;

    int temporary;

    while(temp)
    {
        sortnode=store;
        while(sortnode)
        {
            if(sortnode->next && sortnode->data > sortnode->next->data)
            {
                temporary=sortnode->data;
                sortnode->data=sortnode->next->data;
                sortnode->next->data=temporary;
            }
            sortnode=sortnode->next;
        }
        temp=temp->next;
    }
}

int main()
{
    int sz;
    printf("Enter number of elements: ");
    scanf("%d",&sz);
    int i;

    for(i=0;i<sz;i++)
    {
        insertatB();
    }

    bubblesort(head);

    printf("\nSorted list : ");
    Display();
}
