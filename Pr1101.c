#include<stdio.h>

int main()
{
  int array[100], sz, i, j, temp;

  printf("\nEnter number of elements: ");
  scanf("%d", &sz);



  for (i = 0; i < sz; i++)
  {
      printf("\nEnter values %d: ",i+1);
      scanf("%d", &array[i]);
  }

  for (i = 0 ; i < sz - 1; i++)
  {
    for (j = 0 ; j < sz - i - 1; j++)
    {
      if (array[j] > array[j+1])
      {
        temp=array[j];
        array[j]   = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  printf("Sorted list :\n");

  for (i = 0; i < sz; i++)
     printf("%d ", array[i]);

  return 0;
}
