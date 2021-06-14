#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *left, *right;
} NODE;

NODE *create(NODE *root, int x)
{
    NODE *getnode;
    if (root == NULL)
    {
        root = (NODE *)malloc(sizeof(NODE));
        root->info = x;
        root->left = root->right = NULL;
    }
    else if (x > root->info)
        root->right = create(root->right, x);
    else if (x < root->info)
        root->left = create(root->left, x);
    else
    {
        printf("Duplicate node\n");
        exit(0);
    }
    return (root);
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%5d", root->info);
        inorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%5d", root->info);
    }
}

void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%5d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int height(NODE *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int printBalanceFactor(NODE *root)
{
    if (root != NULL)
    {
        printf("\nBalance factor of node with value %d : %d", root->info, height(root->left) - height(root->right));
        printBalanceFactor(root->left);
        printBalanceFactor(root->right);
    }
}

void main()
{
    int n, x, ch, i;
    NODE *root;
    root = NULL;
    printf("-----------Menu-----------\n");
    printf(" 1. Insert\n 2. All traversals\n 3. Get Balance Factor\n 4. Exit\n");
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter node (do not enter duplicate nodes) : ");
            scanf("%d", &x);
            root = create(root, x);
            break;
        case 2:
            printf("\n*********************************************");
            printf("\nInorder traversal   : ");
            inorder(root);
            printf("\nPreorder traversal  : ");
            preorder(root);
            printf("\nPostorder traversal : ");
            postorder(root);
            printf("\n\n*********************************************\n");
            break;
        case 3:
            printf("\n*********************************************");
            printBalanceFactor(root);
            printf("\n\n*********************************************\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}