#include<stdio.h>
#include<stdlib.h>
struct llnode
{
    int data;
    struct llnode* next;
}*head=NULL;

void insertatB();
void Display();
void DeleteatB();
void searchrec(struct llnode*,int);
void searchcall();

int main()
{
    int choice;

    printf("1.Insert \n2.Delete \n3.Display\n4.search\n5.exit\n");
    while(choice!=5)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertatB();
            break;
        case 2:
           DeleteatB();
           break;
        case 3:
            Display();
            break;
        case 4:
            searchcall();
            break;
        case 5:
            break;
        }
    }
}

void searchrec(struct llnode* head,int sval)
{
    if(head->data==sval)
        printf("\n value found !");
    if(head->next==NULL)
    {
        return;
    }
    searchrec(head->next,sval);
}

void searchcall()
{
    int s;
    printf("\nenter value to search : ");
    scanf("%d",&s);
    searchrec(head,s);
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
