#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void heapify(int h[], int l, int n)
{
    int i, k, v, heapify, j;
    for(i = (n/2); i>=l; i--)
    {
        k = i; v = h[k]; heapify = 0;
        while(heapify == 0 && 2*k <= n)
        {
            j = 2*k;
            opcount++;
            if(j<n)
                if(h[j]<h[j+1])
                    j = j+1;
            if(v>=h[j])
                heapify = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
    return;
}

void heapSort(int arr[], int n)
{
    int k = 0;
    for(int i = 1; i<=n; i++)
    {
        heapify(arr, 1, n - k);
        int temp = arr[1];
        arr[1] = arr[n-k];
        arr[n-k] = temp;
        k++;
    }
}


int main()
{
    int heap[100], n, i, j;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 1; i <= n; i++)
        scanf("%d", &heap[i]);
    heapSort(heap, n);
    printf("Sorted array : ");
    for (i = 1; i <= n; i++)
        printf("%d ", heap[i]);
    printf("\nOpcount = %d\n", opcount);
    return 0;
}