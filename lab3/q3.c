// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// struct Stack
// {
//   int top;
//   unsigned capacity;
//   int *array;
// };

// struct Stack *createStack(unsigned capacity)
// {
//   struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
//   stack->capacity = capacity;
//   stack->top = -1;
//   stack->array = (int *)malloc(stack->capacity * sizeof(int));
//   return stack;
// }

// int isFull(struct Stack *stack)
// {
//   return stack->top == stack->capacity - 1;
// }

// int isEmpty(struct Stack *stack)
// {
//   return stack->top == -1;
// }

// void push(struct Stack *stack, int item)
// {
//   if (isFull(stack))
//     return;
//   stack->array[++stack->top] = item;
// }

// int pop(struct Stack *stack)
// {
//   if (isEmpty(stack))
//     return INT_MIN;
//   return stack->array[stack->top--];
// }

// void printSets(struct Stack *set1, struct Stack *set2)
// {
//   int i;
//   printf("Subset 1 : ");
//   for (i = 0; i <= set1->top; i++)
//   {
//     printf("%d ", set1->array[i]);
//   }
//   printf("\nSubset 2 : ");
//   for (i = 0; i <= set2->top; i++)
//   {
//     printf("%d ", set2->array[i]);
//   }
// }

// int findSets(int arr[], int n, struct Stack *set1, struct Stack *set2, int sum1, int sum2, int pos)
// {
//   if (pos == n)
//   {
//     if (sum1 == sum2)
//     {
//       printSets(set1, set2);
//       return 1;
//     }
//     else
//       return 0;
//   }
//   push(set1, arr[pos]);
//   int res = findSets(arr, n, set1, set2, sum1 + arr[pos], sum2, pos + 1);
//   if (res)
//     return res;
//   pop(set1);
//   push(set2, arr[pos]);
//   res = findSets(arr, n, set1, set2, sum1, sum2 + arr[pos],pos + 1);
//   if (res == 0)
//     if (!isEmpty(set2))
//       pop(set2);
//   return res;
// }

// int isPartitionPoss(int arr[], int n)
// {
//   int sum = 0;
//   for (int i = 0; i < n; i++)
//     sum += arr[i];
//   if (sum % 2 != 0)
//     return 0;
//   struct Stack *set1 = createStack(100);
//   struct Stack *set2 = createStack(100);
//   return findSets(arr, n, set1, set2, 0, 0, 0);
// }

// int main(int argc, char const *argv[])
// {
//   int n;
//   printf("Enter the number of elements in the array : ");
//   scanf("%d", &n);
//   int arr[n];
//   printf("Enter the elements of the array : ");
//   for (int i = 0; i < n; i++)
//     scanf("%d", &arr[i]);
//   if (!isPartitionPoss(arr, n))
//   {
//     printf("Partition is not possible.\n");
//   }
// }

// #include <stdbool.h>
// #include <stdio.h>

// bool isSubsetSum(int arr[], int n, int sum)
// {
//   if (sum == 0)
//     return true;
//   if (n == 0 && sum != 0)
//     return false;
//   if (arr[n - 1] > sum)
//     return isSubsetSum(arr, n - 1, sum);
//   return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
// }

// bool findPartiion(int arr[], int n)
// {
//   int sum = 0;
//   for (int i = 0; i < n; i++)
//     sum += arr[i];
//   if (sum % 2 != 0)
//     return false;
//   return isSubsetSum(arr, n, sum / 2);
// }

// int main()
// {
//   int n;
//     printf("Enter the number of elements in the array : ");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter the elements of the array : ");
//     for (int i = 0; i < n; i++)
//       scanf("%d", &arr[i]);
//   if (findPartiion(arr, n) == true)
//     printf("Can be divided into two subsets "
//            "of equal sum");
//   else
//     printf("Can not be divided into two subsets"
//            " of equal sum");
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//   int n,opcount=0;
//   printf("Enter the number of elements in the array : ");
//   scanf("%d", &n);
//   int a[n];
//   printf("Enter the elements of the array : ");
//   int sum = 0;
//   for (int i = 0; i < n; i++)
//   {
//     scanf("%d", &a[i]);
//     sum += a[i];
//   }

//   if (sum & 1)
//   {
//     puts("Partition not possible.");
//     return 0;
//   }

//   int ans = -1;
//   for (int bit = 0; bit < (1 << n); bit++)
//   {
//     int Sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//       opcount++;
//       if (bit & 1 << i)
//         Sum += a[i];
//     }
//     if (2 * Sum == sum)
//     {
//       ans = bit;
//       break;
//     }
//   }

//   if (ans < 0)
//   {
//     puts("Partition not possible.");
//     printf("\nOpcount = %d",opcount);
//   }
//   else
//   {
//     puts("Partition is possible.");
//     printf("Subset 1 : ");
//     for (int i = 0; i < n; i++)
//       if (ans & 1 << i)
//         printf(" %d", a[i]);

//     printf("\nSubset 2 : ");
//     for (int i = 0; i < n; i++)
//       if ((ans & 1 << i) == 0)
//         printf(" %d", a[i]);
//     printf("\nOpcount = %d",opcount);
//   }
// }

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef enum
{
  false,
  true
} bool;

int size;
int opcount;
int *kc;
int *dkc;

bool subset(int arr[], int n, int sum, int a[])
{
  int *k;
  int *dk;
  k = (int *)calloc(size, sizeof(int));
  dk = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++)
  {
    k[i] = a[i];
    dk[i] = a[i];
  }
  if (sum == 0)
  {
    printf("Possible to partition\n");
    printf("Subset 1: ");
    for (int i = 0; i < size; i++)
    {
      if (a[i])
        printf("%d  ", a[i]);
    }
    printf("\nSubset 2: ");
    int flag;
    for (int i = 0; i < size; i++)
    {
      flag = 1;
      for (int j = 0; j < size; j++)
      {
        if (arr[i] == a[j])
          flag = 0;
      }
      if (flag)
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return true;
  }
  if (n == 0 && sum != 0)
    return false;
  dk[n - 1] = 0;
  opcount++;
  return subset(arr, n - 1, sum, k) || subset(arr, n - 1, sum - arr[n - 1], dk);
}

bool partition(int arr[], int n)
{
  int sum = 0;
  kc = (int *)calloc(size, sizeof(int));
  dkc = (int *)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++)
  {
    kc[i] = arr[i];
    dkc[i] = arr[i];
  }
  for (int i = 0; i < n; i++)
    sum += arr[i];
  if (sum % 2 != 0)
    return false;
  return subset(arr, n, sum / 2, arr);
}

int main()
{

  printf("Enter size of set: \n");
  scanf("%d", &size);
  int *arr = (int *)calloc(size, sizeof(int));
  printf("Enter the set: \n");
  for (int j = 0; j < size; j++)
  {
    scanf("%d", &arr[j]);
  }
  opcount = 0;

  bool flag = partition(arr, size);
  if (flag)
    printf("");
  else
    printf("Not possible to partition\n");
  printf("\nopcount = %d\n", opcount);

  return 0;
}
