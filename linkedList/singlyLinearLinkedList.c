#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList
{
    int info;
    struct singlyLinkedList *next;
} Node;

Node *start = NULL;

Node *initializeNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("\nMemory allocation failed for Node.\n");
        exit(1);
    }
    newNode->info = 0;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegining(int value)
{
    Node *newNode = initializeNode();

    newNode->info = value;

    if (start != NULL)
    {
        newNode->next = start;
    }
    start = newNode;
}

void display()
{
    Node *temp = start;
    printf("\nElements of Node are: ");

    while (temp != NULL)
    {
        printf("%d->", temp->info);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

void search(int value)
{
    Node *temp = start;
    int index = 0;
    do
    {
        if (temp->info == value)
        {
            printf("\n%d is found at index %d\n", value, index);
            return;
        }

        temp = temp->next;
        index++;
    } while (temp != NULL);
    printf("\n%d does not exist in the Node.\n");
}
void deleteLastNode()
{
    if (start == NULL)
    {
        printf("\nNode is empty!!\n");
        return;
    }

    if (start->next == NULL)
    {
        printf("\nDeleted element is %d\n", start->info);
        start = NULL;
    }
    else
    {
        Node *temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("\nDeleted element is %d\n", temp->next->info);
        free(temp->next);
        temp->next = NULL;
    }
}
int main()
{
    int choice;
    int value;
restart:
    printf("\n1.Insert at begining  2.Display all  3.Search for node  4.Delete last node.  5.Exit");
    printf("\nEnter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter value to insert: ");
        scanf("%d", &value);
        insertAtBegining(value);
        break;
    case 2:
        display();
        break;
    case 3:
        printf("Enter value to search: ");
        scanf("%d", &value);
        search(value);
        break;
    case 4:
        deleteLastNode();
        break;
    case 5:
        return 0;
    default:
        printf("Invalid choice! Please try again.");
    }
    goto restart;

    return 0;
}
