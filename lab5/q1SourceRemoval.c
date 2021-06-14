#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (int *)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    // printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

typedef struct listNode ListNode;

struct listNode
{
    ListNode *next;
    int data;
};

ListNode *createNode(int x)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

ListNode *insert(ListNode *head, int x)
{
    if (head == NULL)
    {
        head = createNode(x);
        return head;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = createNode(x);
    return head;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void TSUsingSourceRemoval(ListNode **adjList, int v)
{
    int indegree[v], i;
    for (i = 0; i < v; i++)
        indegree[i] = 0;
    for (i = 0; i < v; i++)
    {
        ListNode *temp = adjList[i];
        while (temp != NULL)
        {
            indegree[temp->data]++;
            temp = temp->next;
        }
        free(temp);
    }
    struct Queue *queue = createQueue(1000);
    for (i = 0; i < v; i++)
        if (indegree[i] == 0)
            enqueue(queue, i);
    int TS[v], idx = 0, cnt = 0;
    while (!isEmpty(queue))
    {
        int u = dequeue(queue);
        TS[idx++] = u;
        ListNode *temp = adjList[u];
        while (temp != NULL)
        {
            if (--indegree[temp->data] == 0)
                enqueue(queue, temp->data);
            temp = temp->next;
        }

        cnt++;
    }
    if (cnt != v)
        printf("There is a cycle in the graph.");
    else
    {
        printf("Topological sort using source removal technique : ");
        for (i = 0; i < v; i++)
            printf("%d ", TS[i]);
    }
}

int main()
{
    int v, e, i, j;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);

    ListNode **adjList = malloc(v * sizeof(ListNode *));
    for (i = 0; i < v; i++)
        adjList[i] = NULL;

    printf("Enter the number of edges : ");
    scanf("%d", &e);
    int start, end, visited[v];
    for (i = 0; i < v; i++)
        visited[i] = 0;
    for (i = 0; i < e; i++)
    {
        printf("Enter start and end vertex of edge %d : ", i + 1);
        scanf("%d%d", &start, &end);
        adjList[start] = insert(adjList[start], end);
    }

    printf("\nAdjacency List : \n");
    for (i = 0; i < v; i++)
    {
        printf("%d : ", i);
        print(adjList[i]);
    }
    printf("\n");

    TSUsingSourceRemoval(adjList, v);
}