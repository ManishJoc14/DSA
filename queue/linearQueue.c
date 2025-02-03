#include <stdio.h>
#include <stdlib.h>

typedef struct LinearQueue
{
    int front, rear, size, *values;
} Queue;

Queue *initializeQueue(int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
    {
        printf("Memory allocation failed for queue.\n");
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    q->size = size;
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
    if (q->rear >= q->size - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        q->values[++q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    else
    {
        return q->values[q->front++];
    }
}

void displayAll(Queue *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nElements of queue are: ");
    int i = q->front;

    while (i <= q->rear)
    {
        printf("%d ", q->values[i++]);
    }
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