#include <stdio.h>
#include<stdlib.h>
struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
}*root=NULL;

struct tnode *CreateBST(struct tnode *, int);
struct tnode* deletenode(struct tnode*,int);
struct tnode* minvalue(struct tnode*);

int main()
{
    int i,n,item;
    int flag=0;
    int searchitem;
   // int deleteval;
            root = NULL;
            printf("\n\nHow Many Nodes ? ");
            scanf("%d",&n);
            for(i = 1; i <= n; i++)
            {
                printf("\nEnter data : ");
                scanf("%d",&item);
                root = CreateBST(root,item);
            }

       root=deletenode(root,12);
}

struct tnode *CreateBST(struct tnode *root, int item)
{
    if(root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if(item < root->data )
            root->left = CreateBST(root->left,item);
        else if(item > root->data )
            root->right = CreateBST(root->right,item);
        else
            root->left = CreateBST(root->left,item);

        return(root);
    }
}

struct tnode* minvalue(struct tnode* temp)
{
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

struct tnode* deletenode(struct tnode* temp,int num)
{
   // printf("\nHERE ");
        if(temp==NULL)
        {
            return NULL;
        }
        else if(num<temp->data)
        {
            temp->left=deletenode(temp->left,num);
        }
        else if(num>temp->data)
        {
            temp->right=deletenode(temp->right,num);
        }
        else
        {
            if(temp->left==NULL)
            {
                struct tnode* temp1=temp->right;
                printf("\nNODE DELETED !");
                free(temp);
                return temp1;
            }
            else if(temp->right==NULL)
            {
                struct tnode* temp1=temp->left;
                printf("\nNODE DELETED !");
                free(temp);
                return temp1;
            }
            else
            {
                struct tnode* temp1;
                temp1=minvalue(temp->right);
                temp->data=temp1->data;
                temp->right=deletenode(temp->right,temp1->data);
            }
        }
        return temp;
}
