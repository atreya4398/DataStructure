#include <stdio.h>

int main()
{
  int array[100], search, i, sz;

  printf("Enter number of elements in array: ");
  scanf("%d", &sz);

  for (i = 0; i < sz; i++)
  {
      printf("\nEnter values %d: ",i+1);
      scanf("%d", &array[i]);
  }

  printf("Enter a value to search: ");
  scanf("%d", &search);

  for (i = 0; i < sz; i++)
  {
    if (array[i] == search)
    {
      printf("%d is found at location %d.\n", search, i+1);
      break;
    }
  }
  if (i == sz)
    printf("%d not found.\n", search);

  return 0;
}
