#include <stdio.h>
int opcount = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int i, pivot = A[r], pivotidx = l;
        for (i = l; i < r; i++)
        {
            opcount++;
            if (A[i] <= pivot)
            {
                swap(&A[i], &A[pivotidx]);
                pivotidx++;
            }
        }
        swap(&A[pivotidx], &A[r]);
        quickSort(A, l, pivotidx - 1);
        quickSort(A, pivotidx + 1, r);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of integers : ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the integers : ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    quickSort(A, 0, n - 1);
    printf("The sorted array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\nOpcount = %d\n", opcount);
}