
#include<stdio.h>
#include<stdlib.h>

void sort(int *arr,int top);
void copy(int *src, int *dest, int top);
void push(int *stack, int *top,int val);
int pop(int *stack, int *top);
void display(int *stack, int *top);

int main()
{
	int arr[15];
	int top = -1;

	push(arr, &top, 10);
	push(arr, &top, 9);
	push(arr, &top, 11);
	push(arr, &top, 15);
	push(arr, &top, 5);
	push(arr, &top, 20);

	printf("Stack Before :- ");
	display(arr,&top);

	sort(arr,top);

	printf("Stack After :- ");
	display(arr, &top);

	return 0;
}

void display(int *stack, int *top) {

	int i;

	if (*top == -1) {
		printf("Stack is empty !");
	}
	else {
		printf(" [ ");
		for (i = 0; i <= *top; i++) {
			printf("%d",stack[i]);
			if (i < *top)
				printf(" , ");
		}
		printf(" ] ");
	}
	printf("\n");
}

void push(int *arr, int *top, int val) {
	arr[++(*top)] = val;
}

int pop(int *arr, int *top) {
	return arr[(*top)--];
}

void sort(int *arr, int top) {

	int temp_val;
	int temp_arr[100];
	int item;
	int temp_top = -1;

	while(top != -1) {
		temp_val = pop(arr, &top);
		while (temp_top != -1 && temp_arr[temp_top] > temp_val) {
			item = pop(temp_arr, &temp_top);
			push(arr, &top, item);
		}
		push(temp_arr, &temp_top, temp_val);
	}
	copy(temp_arr, arr, temp_top);
}

void copy(int *src, int *dest, int top) {

	int temp_arr[100];
	int temp_top = -1;

	while (top != -1) {
		push(temp_arr, &temp_top, pop(src, &top));
	}

	while (temp_top != -1) {
		push(dest, &top, pop(temp_arr, &temp_top));
	}
}
