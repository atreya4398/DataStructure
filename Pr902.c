#include <stdio.h>
#include<stdlib.h>
struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
}*root=NULL;

struct tnode *CreateBST(struct tnode *, int);
int searchval(struct tnode *,int);

int main()
{
    int i,n,item;
    int flag=0;
    int searchitem;
            root = NULL;
            printf("\n\nHow Many Nodes ? ");
            scanf("%d",&n);
            for(i = 1; i <= n; i++)
            {
                printf("\nEnter data : ");
                scanf("%d",&item);
                root = CreateBST(root,item);
            }

        printf("\nEnter data to search : ");
        scanf("%d",&searchitem);

       flag=searchval(root,searchitem);

        if(flag==1)
            printf("\nFound in BST !");
        else
            printf("\nNot Found !");

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

int searchval(struct tnode* temp,int num)
{
    while(temp!=NULL)
    {
        if(num>temp->data)
        {
            temp=temp->right;
        }
        else if(num<temp->data)
        {
            temp=temp->left;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
