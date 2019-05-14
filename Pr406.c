#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int *arr = (int *)calloc(5, sizeof(int));

    push(arr, 15);
    push(arr, 2);
    push(arr, 45);
    push(arr, 22);
    push(arr, 9);

    printf("Stack before sorting:\n");
    display(arr);

    sort(arr);

    printf("\nStack after sorting:\n");
    display(arr);

    return 0;
}
