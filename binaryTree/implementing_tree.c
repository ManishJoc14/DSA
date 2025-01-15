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
    Node *root = NULL;
    root = insertValue(root, 5);
    root = insertValue(root, 10);
    root = insertValue(root, 11);
    root = insertValue(root, 7);
    root = insertValue(root, 6);
    root = insertValue(root, 15);

    printf("Inorder  : ");
    inOrderTraversal(root);
    printf("\n");

    printf("Postorder: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Preorder : ");
    preOrderTraversal(root);
    printf("\n");

    root = deleteNode(root, 10);
    printf("Inorder  : ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}