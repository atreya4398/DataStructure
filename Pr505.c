#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *first, *sec, *third;

void create()
{
    int c;

    first = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &first->data);
    first->next = first;
    head = first;
    printf("\n to continue press 1 otherwise 0:");
    scanf("%d", &c);
    while (c != 0)
    {
        sec = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data:");
        scanf("%d", &sec->data);
        first->next = sec;
        sec->next = head;
        first = sec;
        printf("\n to continue press 1 otherwise 0:");
        scanf("%d", &c);
    }
}


void insatbeg()
{
    first = head;
    int info;
    sec = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d",&info);
    printf("\nhere");
    sec->next=NULL;
    sec->data=info;
    while (first->next != head)
    {
        first = first->next;
    }
    first->next = sec;
    sec->next = head;
    head = sec;
    printf("\nINSERTED !");
}

void delatbeg()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        first = head;
        sec = head;
        while (first->next !=  head)
        {
            first = first->next;
        }
        head = sec->next;
        first->next = head;
        free(sec);
    }
    printf("\nDeleted ");
}

void display()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        first = head;
        while (first->next !=  head)
        {
            printf("%d->", first->data);
            first = first->next;
        }
        printf("%d", first->data);
    }
}


int main()
{
    int choice;

    while(choice!=5)
    {
        printf("\n1.create\n2.insert\n3.delete\n4.display\n5.exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            insatbeg();
            break;
        case 3:
            delatbeg();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        }
    }
}
