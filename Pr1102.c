#include <stdio.h>

int main()
{
  int array[100], sz, i, j, index, temp;

  printf("Enter number of elements: ");
  scanf("%d", &sz);

  for (i = 0; i < sz; i++)
  {
      printf("\nEnter values %d: ",i+1);
      scanf("%d", &array[i]);
  }


  for (i = 0; i < (sz - 1); i++)
  {
    index = i;

    for (j = i + 1; j < sz; j++)
    {
      if (array[index] > array[j])
        index = j;
    }
    if (index != i)
    {
      temp = array[i];
      array[i] = array[index];
      array[index] = temp;
    }
  }

  printf("Sorted list : ");

  for (i = 0; i < sz; i++)
    printf("%d ", array[i]);

  return 0;
}
