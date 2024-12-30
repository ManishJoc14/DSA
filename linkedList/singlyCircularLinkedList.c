#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedNode
{
    int info;
    struct singlyLinkedNode *next;
} Node;

Node *start = NULL;
Node *last = NULL;

Node *initializeNode()
{
    Node *l = (Node *)malloc(sizeof(Node));
    if (l == NULL)
    {
        printf("\nMemory allocation failed for Node.");
        exit(1);
    }
    l->info = 0;
    return l;
}

void insertAtBegining(int value)
{
    Node *new_node = initializeNode();

    new_node->info = value;

    if (start == NULL)
    {
        start = new_node;
        last = new_node;
    }
    else
    {
        last = start;
        new_node->next = start;
    }
}

void display()
{
    Node *temp = start;
    printf("\nElements of Node are: ");

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

void search(int value)
{
    Node *temp = start;
    int index = 0;
    do
    {
        if (temp->info == value)
        {
            printf("\n%d is found at index %d", value, index);
            return;
        }

        temp = temp->next;
        index++;
    } while (temp != NULL);
    printf("\n%d does not exist in the Node.");
}
void deleteLastNode()
{
    Node *ptr;

    if (start == NULL || last == NULL)
    {
        printf("\nNode is empty!!");
        return;
    }
    else if (start == last)
    {
        printf("\n1Deleted element is %d", start->info);
        start = NULL;
        last = NULL;
    }
    else
    {
        while (ptr->next != last)
        {
            ptr = ptr->next;
        };
        last = ptr;
        last->next = start;
        printf("\n2Deleted element is %d", last->info);
        free(ptr);
    }
}

int main()
{
    insertAtBegining(10);
    insertAtBegining(20);
    insertAtBegining(30);
    insertAtBegining(40);
    display();

    search(20);
    search(40);
    deleteLastNode();
    deleteLastNode();
    display();

    return 0;
}
