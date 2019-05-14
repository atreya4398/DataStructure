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

void postorder(struct Btree* temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf(" %d ",temp->data);
    }
}

int main()
{
    struct Btree* root=newnode(1);

    root->left=newnode(2);
    root->right=newnode(3);

    root->left->left=newnode(4);

    printf("\nTree is created !");

    printf("\n");

    postorder(root);
}

