#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void TD(int heap[], int curr)
{
    int parent = (curr - 1) / 2;
    while (parent >= 0)
    {
        opcount++;
        if (heap[parent] < heap[curr])
        {
            swap(&heap[parent], &heap[curr]);
            curr = parent;
            parent = (curr - 1) / 2;
        }
        else
            return;
    }
}

int main()
{
    int heap[100], n, i, j;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
        TD(heap, i);
    }
    printf("Heapified array : ");
    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\nOpcount = %d\n", opcount);
    return 0;
}