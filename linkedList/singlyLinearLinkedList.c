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
    newNode->next = start;
    start = newNode;
}

void insertAtPosition(int value, int position)
{

    if (position == 0) // Insert at beginning
    {
        insertAtBegining(value);
        return;
    }

    Node *newNode = initializeNode();
    newNode->info = value;

    Node *temp = start;
    int i = 0;

    // loop until temp exits and index is less than position-1
    while (temp && i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) // Position out of bounds
    {
        printf("\nInvalid position! Cannot insert.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    Node *temp = start;
    printf("\nElements of Node are: ");

    // print until temp exists
    while (temp)
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
        // temp is secondlast so, temp->next is last
        printf("\nDeleted element is %d\n", temp->next->info);
        free(temp->next);
        temp->next = NULL;
    }
}
int main()
{
    int choice;
    int value;
    int position;
restart:
    printf("\n1.Insert at begining  2.Display all  3.Search for node  4.Delete last node. 5.Insert at any position  6.Exit");
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
        printf("Enter position: ");
        scanf("%d", &position);
        printf("Enter value to insert: ");
        scanf("%d", &value);
        insertAtPosition(value, position);
        break;
    case 6:
        return 0;
    default:
        printf("Invalid choice! Please try again.");
    }
    goto restart;

    return 0;
}
