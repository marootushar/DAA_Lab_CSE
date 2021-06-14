#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct priorityQueue
{
    int size;
    int *heap;
};

struct priorityQueue *createQueue()
{
    struct priorityQueue *queue = (struct priorityQueue *)malloc(sizeof(struct priorityQueue));
    queue->heap = (int *)malloc(MAX * sizeof(int));
    queue->size = 0;
    return queue;
}

int isEmpty(struct priorityQueue *queue)
{
    return (queue->size == 0);
}

void heapifyBU(int arr[], int n, int i)
{
    int parent = (i - 1) / 2;
    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(&arr[i], &arr[parent]);
            heapifyBU(arr, n, parent);
        }
    }
}

void heapifyTD(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapifyTD(arr, n, largest);
    }
}

void enqueue(struct priorityQueue *queue, int Key)
{
    queue->size++;
    queue->heap[queue->size -1] = Key;
    heapifyBU(queue->heap, queue->size, queue->size - 1);
}

void dequeue(struct priorityQueue *queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    int lastElement = queue->heap[queue->size - 1];
    printf("%d Dequeued.\n", queue->heap[0]);
    queue->heap[0] = lastElement;
    queue->size--;
    heapifyTD(queue->heap, queue->size, 0);
}

void printQueue(struct priorityQueue *queue)
{
    printf("Queue : ");
    for (int i = 0; i < queue->size; i++)
        printf("%3d", queue->heap[i]);
    printf("\n");
}

void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--) {
        heapifyTD(arr, n, i);
    }
}

void removeAll(struct priorityQueue *queue, int x)
{
    int lastElement = queue->heap[queue->size - 1];
    int arr[MAX],size=0;
    for(int i = 0; i < queue->size; i++)
    {
        if(queue->heap[i]!=x)
        {
            arr[size++]=queue->heap[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        queue->heap[i]==arr[i];
    }
    queue->size=size;
    buildHeap(queue->heap,size);
}


int main()
{
    int n, x, ch, i;
    struct priorityQueue *queue = createQueue(100);
    printf("-----------Menu-----------\n");
    printf(" 1. Enqueue\n 2. Dequeue\n 3. Print\n 4. Remove\n 5. Exit\n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d", &x);
            enqueue(queue, x);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            printf("Enter value : ");
            scanf("%d", &x);
            removeAll(queue, x);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}