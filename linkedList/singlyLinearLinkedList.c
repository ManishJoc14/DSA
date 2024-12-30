#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLinkedList
{
    int info;
    struct singlyLinkedList *next;
} List;

List *start = NULL;

List *initializeList()
{
    List *l = (List *)malloc(sizeof(List));
    if (l == NULL)
    {
        printf("\nMemory allocation failed for list.");
        exit(1);
    }
    l->info = 0;
    l->next = NULL;
    return l;
}

void insertAtBegining(int value)
{
    List *l = initializeList();

    l->info = value;

    if (start != NULL)
    {
        l->next = start;
    }
    start = l;
}

void display()
{
    List *temp = start;
    printf("\nElements of list are: ");

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

void search(int value)
{
    List *temp = start;
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
    printf("\n%d does not exist in the list.");
}
void deleteLastNode()
{
    List *secondLast, *last = start;

    if (start == NULL)
    {
        printf("\nList is empty!!");
        return;
    }
    else if (start->next == NULL)
    {
        printf("\nDeleted element is %d", start->info);
        start = NULL;
    }
    else
    {
        while (last->next != NULL)
        {
            secondLast = last;
            last = last->next;
        };
        secondLast->next = NULL;
        printf("\nDeleted element is %d", last->info);
        free(last);
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
