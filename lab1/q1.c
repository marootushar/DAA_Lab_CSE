#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
  Node *left;
  Node *right;
  int data;
};

void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d\t", root->data);
  inorder(root->right);
}

void preorder(Node *root)
{
  if (root == NULL)
    return;
  printf("%d\t", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d\t", root->data);
}

Node *search(Node *root, int x)
{
  if (root == NULL)
  {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    printf("Key Inserted.\n");
    return temp;
  }
  if (x == root->data)
  {
    printf("Key Found.\n");
  }
  else if (x > root->data)
  {
    root->right=search(root->right, x);
  }
  else
  {
    root->left=search(root->left, x);
  }
  return root;
}

int main()
{
  Node *binTree = NULL;
  int x, key;
  printf("Command Menu : \n");
  printf("1 : Enter Key.\n");
  printf("2 : Inorder Traversal.\n");
  printf("3 : Preorder Traversal.\n");
  printf("4 : Postorder Traversal.\n");
  printf("5 : Exit.\n");
  printf("Enter Command : ");
  scanf("%d", &x);
  while (x != 5)
  {
    switch (x)
    {
    case 1:
      printf("Enter Key : ");
      scanf("%d", &key);
      binTree = search(binTree, key);
      break;
    case 2:
      printf("Inorder : ");
      inorder(binTree);
      printf("\n");
      break;
    case 3:
      printf("Preorder : ");
      preorder(binTree);
      printf("\n");
      break;
    case 4:
      printf("Postorder : ");
      postorder(binTree);
      printf("\n");
      break;
    default:
      printf("Invalid Command.\n");
      break;
    }
    printf("Enter Command : ");
    scanf("%d", &x);
  }
}