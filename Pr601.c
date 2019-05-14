#include<stdio.h>
#include<stdlib.h>

struct llnode
{
    int data;
    struct llnode* next;
}*head=NULL;

void insertatB();
void insertatL();
void insertatpos();
void Display();
void DeleteatB();
void DeleteatL();
void Deleteatpos();

int main()
{
    int choice;

    printf("1.Insert at Beginning\n2.Insert at last\n3.insert at position\n4.Delete at beginning\n5.Delete at end\n6.Delete at position\n7.Display\8.exit\n");
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
           DeleteatB();
           break;
        case 5:
            DeleteatL();
            break;
        case 6:
            Deleteatpos();
            break;
        case 7:
            Display();
            break;
        case 8:
            exit(0);
        }
    }
}

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
        printf("\nNode Inserted successfully !");
    }

}

void insertatL()
{
    int info;
    struct llnode* newnode=(struct llnode*)malloc(sizeof(struct llnode));
    struct llnode* tmp;
    if(newnode==NULL)
    {
        printf("\nOVERFLOW !");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&info);
        newnode->data=info;
        newnode->next=NULL;

            tmp=head;
            while(tmp->next!=NULL)
            {
                tmp=tmp->next;
            }
            tmp->next=newnode;
           // newnode->next=NULL;
            printf("\nNode Inserted");

    }
}

void insertatpos()
{
    struct llnode* newnode=(struct llnode*)malloc(sizeof(struct llnode));
    struct llnode* tmp;
    int loc,i;
    int info;
    if(newnode==NULL)
    {
        printf("\nOVERFLOW !");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&info);

        newnode->data=info;

        printf("\nEnter location: ");
        scanf("%d",&loc);
        tmp=head;
        for(i=1;i<loc;i++)
        {
            tmp=tmp->next;
            if(tmp==NULL)
            {
                printf("\nLocation can't match!");
            }
        }
        newnode->next=tmp->next;
        tmp->next=newnode;
        printf("\nNode Inserted!");
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


void DeleteatB()
{
    struct llnode* tmp;
    if(head==NULL)
    {
        printf("List is empty!");
    }
    else
    {
        tmp=head;
        head=tmp->next;
        free(tmp);
        printf("Deleted from beginning!");
    }
}

void DeleteatL()
{
    struct llnode *tmp,*prev;

    if(head==NULL)
    {
        printf("\nList is empty!");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else
    {
        tmp=head;
        while(tmp->next!=NULL)
        {
            prev=tmp;
            tmp=tmp->next;
        }
        prev->next=NULL;
        free(tmp);
    }
}

void Deleteatpos()
{
    struct llnode *tmp,*prev;

    int loc,i;

    printf("\nEnter location:  ");
    scanf("%d",&loc);
    tmp=head;

    for(i=1;i<loc;i++)
    {
        prev=tmp;
        tmp=tmp->next;
        if(tmp==NULL)
        {
            printf("NO nodes to delete !");
        }
    }
    prev->next=tmp->next;
    free(tmp);
    printf("\nNode Deleted !");
}

