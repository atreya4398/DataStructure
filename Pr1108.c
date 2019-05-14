#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

int binarySearch(struct node *q, int start, int end, int val);

int main()
{
    struct node *head, *p, *q;
    int x;
    int count = 0;

    head = (struct node*)malloc(sizeof(struct node));
    p = (struct node*)malloc(sizeof(struct node));

    head = NULL;
    q = NULL;

MENU:
    system("cls");
    printf("Select :-\n1) Add Linked List\n2) Display\n3) Search\n4) Exit\nEnter : ");
    scanf("%d",&x);
    printf("\n");

    switch (x)
    {
    case 1:
    {
        q = (struct node*)malloc(sizeof(struct node));
        if (q == NULL)
        {
            printf("No Space Available\n");
            break;
        }
        printf("Enter Data : ");
        scanf("%d",&q->data);
        printf("\n");
        q->next = NULL;
        if (head == NULL)
        {
            head = q;
            count++;
        }
        else
        {
            p = head;

            while (p->next != NULL)
            {
                p = p->next;
            }

            p->next = q;
            count++;
        }
    }
    break;
    case 2:
    {
        p = head;
        while (p != NULL)
        {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
    break;
    case 3:
    {
        printf("Enter the Search Number : ");
        scanf("%d",&x);
        p = head;

        x = binarySearch(p, 0, count - 1, x);
        if(x == -1)
            printf("\n not found !");
        else
            printf("\nFound at index : %d",x+1);
    }
    break;
    default:
        exit(0);
        break;
    }

    printf("Select :-\n1) Main Menu\n2) Exit\nEnter : ");
    scanf("%d",&x);

    if (x == 1)
    {
        goto MENU;
    }

    return 0;
}

int binarySearch(struct node *p, int start, int end, int val)
{
    int mid;
     struct node *q = (struct node*)malloc(sizeof(struct node));
    while (start <= end)
    {
        mid = start + (end - start) / 2;

        q = p;
        for (int i = 0; i < mid; i++)
        {
            q = q->next;
        }

        if (q->data == val)
        {
            return mid;
        }

        if (q->data < val)
        {
            start = mid + 1;
        }

        if (q->data > val)
        {
            end = mid - 1;
        }
    }
    return -1;
}
