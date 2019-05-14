#include<stdio.h>
#include<stdlib.h>
struct llnode
{
    int data;
    struct llnode* next;
}*head=NULL;

int reclen=0;

void insertatB();
void Display();
void DeleteatB();
void length();
void recursivedisplay(struct llnode*);
void recurcall();

int main()
{
    int choice;

    printf("1.Insert \n2.Delete \n3.Display\n4.Iterative length\n5.Recursive length\n6.exit\n");
    while(choice!=6)
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
            length();
            break;
        case 5:
            recurcall();
            break;
        case 6:
            break;
        }
    }
}

void recursivedisplay(struct llnode* head)
{

    if(head==NULL)
    {
        return;
    }
    recursivedisplay(head->next);

    reclen++;
}

void recurcall()
{
    recursivedisplay(head);
    printf(" Length : %d",reclen);
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

void length()
{
    struct llnode* tmp;
    tmp=head;
    int length=0;

    if(tmp==NULL)
    {
        printf("List is empty !");
    }
    else
    {
        while(tmp!=NULL)
        {
            length++;
            tmp=tmp->next;
        }
        printf("\n Length : %d",length);
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



