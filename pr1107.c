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
        printf("\n Inserted !");
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

void selectionsort(struct llnode* temp)
{
    struct llnode* sortnode=NULL;
    struct llnode* snode=NULL;

    int val;

    while(temp)
    {
        sortnode=temp;
        snode=temp->next;

        while(snode)
        {
            if(snode->data < sortnode->data)
            {
                sortnode=snode;
            }
            snode=snode->next;
        }
        if(sortnode!=temp)
        {
            val=sortnode->data;
            sortnode->data=temp->data;
            temp->data=val;
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

    selectionsort(head);

    printf("\nSorted list : ");
    Display();
}

