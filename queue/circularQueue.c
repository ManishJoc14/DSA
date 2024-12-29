#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int head, tail, size, *values;
} Queue;

Queue *initializeQueue(int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Memory allocation failed for queue.\n");
        exit(1);
    }
    q->head = 0;
    q->tail = 0;
    q->size = size + 1;
    q->values = (int *)malloc(sizeof(int) * size);
    if (q->values == NULL)
    {
        printf("Memory allocation failed for values.\n");
        free(q);
        exit(1);
    }
    return q;
}

void enqueue(Queue *q, int value)
{
    if (q->head == (q->tail + 1) % q->size)
    {
        printf("Queue is full.\n");
    }
    else
    {
        q->values[q->tail] = value;
        q->tail = (q->tail + 1) % q->size;
    }
}

int dequeue(Queue *q)
{
    if (q->head == q->tail)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        int item = q->values[q->head];
        q->head = (q->head + 1) % q->size;
        return item;
    }
}

void displayAll(Queue *q)
{
    if (q->head == q->tail)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nElements of queue are: ");
    int index = q->head;

    do
    {
        printf("%d ", q->values[index]);
        index = (index + 1) % q->size;
    } while (index != q->tail);
}

int main()
{
    int size = 5, choice, value;
    Queue *q = initializeQueue(size);

restart:
   printf("\n1. Enqueue  ");
    printf("2. Dequeue  ");
    printf("3. DisplayALl  ");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter element to enqueue: ");
        scanf("%d", &value);
        enqueue(q, value);
        goto restart;

    case 2:
        printf("\n%d dequed.\n", dequeue(q));
        goto restart;

    case 3:
        displayAll(q);
        goto restart;
    case 4:
        goto exit;

    default:
        printf("\nWrong choice");
        goto exit;
    }

exit:

    free(q->values);
    free(q);
    return 0;
}