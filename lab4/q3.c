#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int rear = -1;
int front = -1;

void enqueue(int item)
{
	if (rear == MAX - 1)
		printf("Queue Overflow \n");
	else
	{
		if (front == -1)
			front = 0;
		rear++;
		queue[rear] = item;
		printf("Inserted %d.\n",item);
	}
}

int dequeue ()
{
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow \n");
		return -1;
	}
	else
	{
		printf("Deleted %d.\n",queue[front]);
		front++;
		return queue[front-1];
	}
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

void bfs(ListNode **adjList,int visited[],int BFS[],int v)
{
	int idx=0;
	visited[v]=1;
	enqueue(v);
	while(!(front == -1 || front > rear))
	{
		v=dequeue();
		BFS[idx++]=v;
		ListNode *temp = adjList[v];
        while (temp != NULL)
        {
            if (!visited[temp->data])
			{
				visited[temp->data]=1;
				enqueue(temp->data);
			}
            temp = temp->next;
        }
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
	int start, end, visited[v], BFS[v];
	for (i = 0; i < v; i++)
		visited[i] = 0;
	for (i = 0; i < e; i++)
	{
		printf("Enter start and end vertex of edge %d : ", i + 1);
		scanf("%d%d", &start, &end);
		adjList[start] = insert(adjList[start], end);
		adjList[end] = insert(adjList[end], start);
	}

	printf("\nAdjacency List : \n");
	for (i = 0; i < v; i++)
	{
		printf("%d : ", i);
		print(adjList[i]);
	}
	printf("\n");
	bfs(adjList, visited, BFS, 0);

	printf("\nBFS : ");
	for (i = 0; i < v; i++)
	{
		printf("%d  ", BFS[i]);
	}
	printf("\n");
}