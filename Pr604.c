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
void middleelement();

int main()
{
    int choice;


    while(choice!=5)
    {
        printf("\n1.Insert\n2.Delete \n3.Display\n4.middle element\n5.exit\n");
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
            middleelement();
            break;
        case 5:
            exit(0);
        }
    }
}

void middleelement()
{
    struct llnode* temp;
    struct llnode* temp1;

    temp1=temp=head;

        while(temp1!=NULL && temp1->next!=NULL)
        {
            temp1=temp1->next->next;
            temp=temp->next;
        }
        printf(" Middle element is : %d",temp->data);
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

