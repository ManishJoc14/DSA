#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *right, *left;
} Node;

Node *createNode(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->right = NULL;
    new_node->left = NULL;
    new_node->val = val;

    return new_node;
}

Node *insertValue(Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }

    if (root->val == val)
    {
        return root;
    }

    if (root->val < val)
    {
        root->right = insertValue(root->right, val);
    }
    else
    {
        root->left = insertValue(root->left, val);
    }

    return root;
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->val);
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

Node *getSuccessor(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node *deleteNode(Node *root, int val)
{

    if (root == NULL)
    {
        return root;
    }

    if (root->val == val)
    {
        // leaf Node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // One child Node
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        // One child Node
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Two child Node
        Node *succ = getSuccessor(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);

        return root;
    }

    if (root->val < val)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        root->left = deleteNode(root->left, val);
    }

    return root;
}

int main()
{
    int choice;
    Node *root = NULL;
    int del_val;
    int val;

    do
    {
        printf("\n1. Insert  2. Delete  3. Inorder  4. Preorder  5. Postorder 6.Exit");
        printf("\nPlease choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            root = insertValue(root, val);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &del_val);
            root = deleteNode(root, del_val);
            break;
        case 3:
            printf("Inorder  : ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder : ");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder: ");
            postOrderTraversal(root);
            printf("\n");
            break;
        case 6:
            return 0;
        default:
            printf("Wrong choice!!");
            break;
        }
    } while (choice >= 1 && choice <= 6);

    return 0;
}