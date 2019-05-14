#include<stdio.h>


void bubblesort(int arr[100],int s)
{
    int temp;
    int i;
    if (s > 0)
    {
        for (i = 1; i < s; i++)
        {
            if (arr[i - 1] > arr[i])
            {

                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }

        bubblesort(arr, s - 1);
    }

}


int main()
{
    int array[100], sz, i;

    printf("\nEnter number of elements: ");
    scanf("%d", &sz);

    for (i = 0; i < sz; i++)
    {
          printf("\nEnter values %d: ",i+1);
          scanf("%d", &array[i]);
    }

    bubblesort(array, sz);

    printf("Sorted list :\n");

  for (i = 0; i < sz; i++)
     printf("%d ", array[i]);
}
