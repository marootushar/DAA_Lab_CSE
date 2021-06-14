#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int opcount = 0;

struct Node
{
    int val;
    struct Node *left, *right;
};

struct Node *newNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int getNodeCount(struct Node *tree)
{
    opcount++;
    if (tree == NULL)
        return 0;
    return 1 + getNodeCount(tree->right) + getNodeCount(tree->left);
}

int main()
{
    struct Node *root = newNode(1);
    int t, i, error = 0;
    printf("Enter the the number of nodes except root node : ");
    scanf("%d", &t);
    while (t--)
    {
        struct Node *temp = root;
        char str[10];
        printf("Enter the location of node : ");
        scanf("%s", str);
        for (i = 0; i < strlen(str) - 1; i++)
        {
            if (str[i] == 'L' || str[i] == 'l')
            {
                temp = temp->left;
            }
            else if (str[i] == 'R' || str[i] == 'r')
            {
                temp = temp->right;
            }
            else
            {
                printf("Invalid String\n");
                break;
            }
            if (temp == NULL)
            {
                printf("Invalid String\n");
                error = 1;
                break;
            }
        }
        if (error == 1)
        {
            error = 0;
            continue;
        }
        if (str[i] == 'L' || str[i] == 'l')
        {
            temp->left = newNode(1);
        }
        else if (str[i] == 'R' || str[i] == 'r')
        {
            temp->right = newNode(1);
        }
        else
        {
            printf("Invalid String\n");
            continue;
        }
        printf("Node Added\n");
    }
    printf("Number of nodes in the given binary tree is : %d\n", getNodeCount(root));
    printf("Opcount = %d\n", opcount);
    return 0;
}