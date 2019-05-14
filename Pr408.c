#include<stdio.h>
#include<stdlib.h>
int stack[100],top=-1,sz;

int newstack[100],newtop=-1;
void push(int);
int Isfull();
int Isempty();
int pop();
//void bottom();
void reverse_stack();
//void display();
int main()
{
    printf("Enter size: ");
    scanf("%d",&sz);

    int choice;
    int i;
    printf("1.Push\n2.Pop\n3.Reverse\n4.exit");
    int info;
    while(choice!=4)
    {
        printf("\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nInsert data into stack: ");
            scanf("%d",&info);
            push(info);
            break;
        case 2:
            pop();
            break;
        case 3:
            reverse_stack();
             for(i=newtop;i>=0;--i)
                printf("| %d |\n",newstack[i]);
  //           display();
            break;
        case 4:
            exit(0);
        default:
            printf("Opps! wrong choice ...");
        }
    }
}
int Isfull()
{
    if(top>=sz)
        return 1;
    else
        return 0;
}
int Isempty()
{
    if(top<0)
        return 1;
    else
        return 0;
}
void push(int val)
{
    if(Isfull()==1)
        printf("\nStack overflow !");
    else
    {
        top++;
        stack[top]=val;
       // printf("\nInserted successfully : %c", stack[top]);
    }
}
int pop()
{
    int data;
    if(Isempty()==1)
        printf("\nStack Underflow !");
    else
    {
        data=stack[top];
       // printf("\nremoved element : %c", stack[top]);
        top--;
    }
    return(data);
}

/*void display()
{
    int i;
    if(Isempty()==1)
        printf("Stack underflow !");
    else
    {
        for(i=top;i>=0;--i)
            printf("| %d |\n",stack[i]);
    }
}*/
/*void bottom(int val)
{
    if(Isempty())
        push(val);
    else
    {
        int toppop=stack[top];
        pop();
        bottom(val);

        push(toppop);
    }

}*/
void reverse_stack()
{
    int toppop;
    if(Isempty()!=1)
    {
        //toppop=stack[top];
       // pop();
        //reverse_stack();

       // bottom(toppop);
        toppop=pop();
        newstack[++newtop]=toppop;
        reverse_stack();

    }

}
