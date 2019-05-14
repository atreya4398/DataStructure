#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

void push(int *stack, int item)
{
    stack[++top] = item;
}

int pop(int *stack)
{
    return stack[top--];
}

int peek(int *stack)
{
    return stack[top];
}

void sortedInsert(int *stack, int val)
{
    if (isEmpty(stack) || val > peek(stack))
    {
        push(stack, val);
        return;
    }
    int temp = pop(stack);
    sortedInsert(stack, val);
    push(stack, temp);
}

void sort(int *stack)
{
    if (!isEmpty(stack))
    {
        int x = pop(stack);
        sort(stack);
        sortedInsert(stack, x);
    }
}
/*
void display(int *stack)
{
    int i;
    if (!isEmpty())
    {
        printf("\nStack :-\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    else
    {
        printf("\nStack is empty !");
    }
    printf("\n");
}
*/
char *sortString(char *str)
{
    int *stack = (int *)calloc(strlen(str), sizeof(int));
    int i;

    for (i = 0; i < strlen(str); i++)
    {
        push(stack, (int)str[i]);
    }

    sort(stack);

    for (i = top; i >= 0; i--)
    {
        str[i] = (int)pop(stack);
    }

    return str;
}

int main()
{
    char *str = (char *)calloc(1024, sizeof(char));

    int *arr = (int *)calloc(5, sizeof(int));

    printf("Enter String : ");
    scanf("%s", str);

    str = sortString(str);

    printf("\nString after Sort : %s", str);

    return 0;
}
