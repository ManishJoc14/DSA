#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList
{
    int info;
    struct singlyLinkedList *next;
} Node;

Node *start = NULL;
Node *last = NULL;

Node *initializeNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("\nMemory allocation failed for Node.");
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

    if (start == NULL)
    {
        start = newNode;
        last = newNode;
        start->next = newNode;
        last->next = newNode;
    }
    else
    {
        newNode->next = start;
        start = newNode;
        last->next = start;
    }
}

void display()
{
    Node *temp = start;
    if (start == NULL)
    {
        printf("\nList is empty!!\n");
        return;
    }

    printf("\nElements of Node are: ");
    while (1)
    {
        printf("%d->", temp->info);
        temp = temp->next;
        if (temp == last->next)
            break;
    }
    printf("START(%d)", last->next->info);
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
    if (start == NULL || last == NULL)
    {
        printf("\nNode is empty!!");
        return;
    }

    if (start == last)
    {
        printf("\nDeleted element is %d", start->info);
        free(last);
        free(start);
        start = NULL;
        last = NULL;
    }
    else
    {
        Node *ptr = start;
        while (ptr->next != last)
        {
            ptr = ptr->next;
        };
        // ptr is secondlast so, ptr->next is last
        ptr->next = start;
        printf("\nDeleted element is %d", last->info);
        free(last);
        last = ptr;
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
