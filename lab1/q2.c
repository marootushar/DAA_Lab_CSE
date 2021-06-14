#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
  Node *next;
  int data;
};

Node *createNode(int x)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = x;
  temp->next = NULL;
  return temp;
}

Node *insert(Node *head, int x)
{
  if (head == NULL)
  {
    head = createNode(x);
    return head;
  }
  Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = createNode(x);
  return head;
}

void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    printf("%d --> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main()
{
  int v, e, i, j;
  printf("Enter the number of vertices : \n");
  scanf("%d", &v);

  int **adjMat = malloc(v * sizeof(int *));
  for (i = 0; i < v; i++)
    adjMat[i] = malloc(v * sizeof(int));
  for (i = 0; i < v; i++)
    for (j = 0; j < v; j++)
      adjMat[i][j] = 0;

  Node **adjList = malloc(v * sizeof(Node *));
  for (i = 0; i < v; i++)
    adjList[i] = NULL;

  printf("Enter the number of edges : \n");
  scanf("%d", &e);
  int start, end;
  for (i = 0; i < e; i++)
  {
    printf("Edge %d : \n", i + 1);
    printf("Enter start vertex : ");
    scanf("%d", &start);
    printf("Enter end vertex : ");
    scanf("%d", &end);
    adjMat[start][end] = 1;
    adjList[start] = insert(adjList[start], end);
  }

  printf("Adjacency Matrix : \n");
  for (i = 0; i < v; i++)
  {
    for (j = 0; j < v; j++)
      printf("%d\t", adjMat[i][j]);
    printf("\n");
  }

  printf("Adjacency List : \n");
  for (i = 0; i < v; i++)
  {
    printf("%d : ", i);
    print(adjList[i]);
  }
}