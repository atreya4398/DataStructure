#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

typedef struct Node
{
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *newNode(int);
void inorder(Node *temp);
void insert(Node *temp, int data);
void enqueue(Node **queue, Node *temp);
int isEmpty();
struct Node *getFront(Node **queue);
void dequeue();
void display(Node **);

int main()
{
    Node *root = newNode(10);
    int data;

    root->lchild = newNode(11);
    root->lchild->lchild = newNode(7);
    root->rchild = newNode(9);
    root->rchild->lchild = newNode(15);
    root->rchild->rchild = newNode(8);

    printf("\nInorder traversal before insertion:");
    inorder(root);
    printf("\n");

    data = 12;
    insert(root, data);

    printf("\nInorder traversal after insertion:");
    inorder(root);
    printf("\n");

    return 0;
}

Node *newNode(int val)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

void inorder(Node *temp)
{
    if (!temp)
        return;

    inorder(temp->lchild);
    printf("%d ", temp->data);
    inorder(temp->rchild);
}

void insert(Node *temp, int data)
{
    Node *queue[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        queue[i] = (Node *)malloc(sizeof(Node));
    }

    enqueue(queue, temp);

    while (!isEmpty())
    {
        Node *temp = getFront(queue);
        dequeue();

        if (!temp->lchild)
        {
            temp->lchild = newNode(data);
            break;
        }
        else
            enqueue(queue, temp->lchild);

        if (!temp->rchild)
        {
            temp->rchild = newNode(data);
            break;
        }
        else
            enqueue(queue, temp->rchild);
    }
}

void enqueue(Node **queue, Node *temp)
{
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = temp;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

Node *getFront(Node **queue)
{
    return queue[front];
}

void dequeue()
{
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display(Node **queue)
{
    int i;

    if (isEmpty())
    {
        printf("Empty");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]->data);
        }
        printf("\n");
    }
}
