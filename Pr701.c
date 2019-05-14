#include<stdio.h>
#include<stdlib.h>
struct dbnode
{
    int data;
    struct dbnode* next;
    struct dbnode* prev;
}*head=NULL;


void insertatB();
void insertatL();
void insertatpos();
void display();
void deleteatB();
void deleteatL();
void deleteatpos();

int main()
{
    int choice;

    printf("1.Insert at beginning\n2.Insert at last\n3.Insert at position\n4.Delete at beginning\n5.Delete at last\n6.Delete at position\n7.Display\n8.exit\n");

    while(choice!=8)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertatB();
            break;
        case 2:
            insertatL();
            break;
        case 3:
            insertatpos();
            break;
        case 4:
            deleteatB();
            break;
        case 5:
            deleteatL();
            break;
        case 6:
            deleteatpos();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        }
    }
}

void insertatB()
{
    struct dbnode* newnode=(struct dbnode*)malloc(sizeof(struct dbnode));

    int info;
    printf("Enter Data: ");
    scanf("%d",&info);

    if(newnode==NULL)
    {
        printf("Overflow !");
    }
    else
    {
        if(head==NULL)
        {
            newnode->next=NULL;
            newnode->prev=NULL;
            newnode->data=info;
            head=newnode;
        }
        else
        {
            newnode->data=info;
            newnode->next=head;
            newnode->prev=NULL;
            head->prev=newnode;
            head=newnode;
        }
        printf("\nINSERTED AT FIRST");
    }
}

void insertatL()
{
    struct dbnode* newnode=(struct dbnode*)malloc(sizeof(struct dbnode));
    struct dbnode* tmp;

    int info;
    printf("\nEnter data: ");
    scanf("%d",&info);

    if(newnode==NULL)
    {
        printf("\nOverflow !");
    }
    else
    {
        newnode->data=info;
        if(head==NULL)
        {
            newnode->next=NULL;
            newnode->prev=NULL;
            head=newnode;
        }
        else
        {
            tmp=head;
            while(tmp->next!=NULL)
            {
                tmp=tmp->next;
            }
            tmp->next=newnode;
            newnode->prev=tmp;
            newnode->next=NULL;
        }
        printf("\nINSERTED AT LAST");
    }
}

void insertatpos()
{
    struct dbnode* newnode=(struct dbnode*)malloc(sizeof(struct dbnode));
    struct dbnode* tmp;

    int loc,i;
    int info;

    if(newnode==NULL)
    {
        printf("\nOverflow !");
    }
    else
    {
        printf("\nEnter location: ");
        scanf("%d",&loc);
        printf("\nEnter data: ");
        scanf("%d",&info);
        tmp=head;
        for(i=1;i<loc;i++)
        {
            tmp=tmp->next;
            if(tmp==NULL)
            {
                printf("\nList is empty !");
            }
        }
        newnode->data=info;
        newnode->next=tmp->next;
        newnode->prev=tmp;
        tmp->next=newnode;
        tmp->next->prev=newnode;
        printf("\nNODE INSERTED !");
    }
}

void display()
{
    struct dbnode* tmp;

    if(head==NULL)
    {
        printf("\nList is empty !");
    }
    else
    {
        tmp=head;
        while(tmp!=NULL)
        {
            printf("%d ==> ",tmp->data);
            tmp=tmp->next;
        }
    }
}

void deleteatB()
{
    struct dbnode* tmp;

    if(head==NULL)
    {
        printf("\nUnderflow !");
    }
    else if(head->next!=NULL)
    {
        head=NULL;
        free(head);
        printf("\NODE DELETED");
    }
    else
    {
        tmp=head;
        head=tmp->next;
        head->prev=NULL;
        free(tmp);
        printf("\nNODE DELETED !");
    }
}

void deleteatL()
{
    struct dbnode* tmp;

    if(head==NULL)
    {
        printf("\nUnderflow !");
    }
    else if(head->next!=NULL)
    {
        head=NULL;
        free(head);
        printf("\nNODE DELETED !");
    }
    else
    {
        tmp=head;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next->prev=NULL;
        free(tmp);
        printf("\nNODE DELETED !");
    }
}

void deleteatpos()
{
    struct dbnode *pre,*tmp;

    int loc;
    printf("\nEnter location: ");
    scanf("%d",&loc);

    tmp=head;
    while(tmp->next!=loc)
    {
        tmp=tmp->next;
    }

    if(tmp->next==NULL)
    {
        printf("\nList is empty !");
    }
    else if(tmp->next->next==NULL)
    {
        tmp->next=NULL;
        printf("\nNODE DELETED !");
    }
    else
    {
        pre=tmp->next;
        tmp->next=pre->next;
        pre->next->prev=tmp;
        free(tmp);
        printf("\nNODE DELETED !");
    }
}

