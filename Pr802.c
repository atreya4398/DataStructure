#include<stdio.h>
#include<stdlib.h>



struct Btree
{
    int data;
    struct Btree* left;
    struct Btree* right;
};


struct Btree* newnode(int data)
{
    struct Btree* node=(struct Btree*)malloc(sizeof(struct Btree));

    node->data=data;

    node->left=NULL;
    node->right=NULL;

    return(node);
}

struct Btree* queue[100];
int rear=0;
int front=-1;

void enqueue(struct Btree* node)
{
    queue[rear++]=node;
}
struct Btree* dequeue()
{
    return queue[++front];
}

void levelOrder(struct Btree* root)
{
    struct Btree* temp=root;
    while(temp)
    {
        printf("%d\t",temp->data);
        if(temp->left)
            enqueue(temp->left);
        if(temp->right)
            enqueue(temp->right);
        temp=dequeue();
    }
}

int main()
{
  //  struct Btree* arr[10]={NULL};;
    struct Btree* root=newnode(1);

    root->left=newnode(2);
    root->right=newnode(3);

    root->left->left=newnode(4);

    printf("\nTree is created !");

    printf("\n");
    levelOrder(root);
}

