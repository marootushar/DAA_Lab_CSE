#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, j, swapped, opcnt = 0;
  printf("Enter the number of elements in the array : ");
  scanf("%d", &n);
  int A[n];
  printf("Enter the elements of the array : ");
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);
  for (i = 0; i < n - 1; i++)
  {
    swapped = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      opcnt++;
      if (A[j] > A[j + 1])
      {
        int temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
  for (i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\nOpcount = %d", opcnt);
}