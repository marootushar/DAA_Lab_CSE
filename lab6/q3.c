#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

void mergeSort(int A[], int n)
{
    if (n <= 1)
        return;
    int L[n / 2], R[n - n / 2];
    int i;
    for (i = 0; i < n / 2; i++)
        L[i] = A[i];
    for (i = n / 2; i < n; i++)
        R[i - n / 2] = A[i];
    mergeSort(L, n / 2);
    mergeSort(R, n - n / 2);
    int lp = 0, rp = 0;
    i = 0;
    while (lp < n / 2 && rp < n - n / 2)
    {
        opcount++;
        if (L[lp] < R[rp])
            A[i++] = L[lp++];
        else
            A[i++] = R[rp++];
    }
    while (lp < n / 2)
    {
        opcount++;
        A[i++] = L[lp++];
    }

    while (rp < n - n / 2)
    {
        opcount++;
        A[i++] = R[rp++];
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
    mergeSort(A, n);
    printf("The sorted array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\nOpcount = %d\n", opcount);
}