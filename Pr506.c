# include<stdio.h>
# define MAX 5

int deque[MAX];
int left = -1;
int right = -1;

void insertatright()
{
	int item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	printf("Queue Overflow\n");
		return;}
	if (left == -1)
	{	left = 0;
		right = 0;}
	else
	if(right == MAX-1)
		right = 0;
	else
		right = right+1;
	printf("Enter data : ");
	scanf("%d", &item);
	deque[right] = item ;
	printf("\nINSERTED !");
}

void insertatleft()
{	int item;
	if((left == 0 && right == MAX-1) || (left == right+1))
	{	printf("Queue Overflow \n");
		return;	 }
	if (left == -1)
	{	left = 0;
		right = 0;	 }
	else
	if(left== 0)
		left=MAX-1;
	else
		left=left-1;
	printf("Enter data : ");
	scanf("%d", &item);
	deque[left] = item ;
    printf("\nINSERTED !");
}


void deleteatleft()
{	if (left == -1)
	{	printf("Queue Underflow\n");
		return ;	}
	printf("Element deleted : %d\n",deque[left]);
	if(left == right)
	{	left = -1;
		right=-1;	 }
	else
		if(left == MAX-1)
			left = 0;
		else
			left = left+1;
}

void deleteatright()
{if (left == -1)
	{printf("Queue Underflow\n");
		return ;	 }
	printf("Element deleted : %d\n",deque[right]);
	if(left == right)
	{	left = -1;
		right=-1;	 }
	else
		if(right == 0)
			right=MAX-1;
		else
			right=right-1;
}

void display()
{	int front = left,rear = right;
	if(left == -1)
	{	printf("Queue is empty\n");
		return;	 }
	printf("Queue elements :\n");
	if( front <= rear )
	{	while(front <= rear)
		{	printf("%d ",deque[front]);
			front++;	}	}
	else
	{	while(front <= MAX-1)
		{	printf("%d ",deque[front]);
			front++;	}
		front = 0;
		while(front <= rear)
		{	printf("%d ",deque[front]);
			front++;
		}
	}
	printf("\n");
}


int main()
{
    int choice;

    while(choice!=6)
    {
        printf("\n1.insert at left\n2.insert at right\n3.delete at left\n4.delete at right\n5.display\n6.exit\n");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insertatleft();
            break;
        case 2:
            insertatright();
            break;
        case 3:
            deleteatleft();
            break;
        case 4:
            deleteatright();
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        }
    }
}
