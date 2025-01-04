#include <stdio.h>

#define max_size 5
int stack[max_size], top = -1;

void push(int value)
{

    if (top == max_size - 1)
    {
        printf("\nStack is full!!");
        return;
    }

    // increase top and then append value
    stack[++top] = value;
    printf("\n%d pushed", stack[top]);
}

void pop()
{

    if (top == -1)
    {
        printf("\nStack is empty!!");
        return;
    }

    printf("\n%d popped", stack[top]);
    // update stack[top] to 0 then decrease top
    stack[top--] = 0;
}

void show()
{
    if (top == -1)
    {
        printf("Stack is empty!!");
        return;
    }

    printf("\nElements of stack are: ");
    for (int i = 0; i <= max_size - 1; i++)
    {
        printf("%d  ", stack[i]);
    }
}

int main()
{
    int choice, value;
    printf("\nStack (Array implementation)\n");

    do
    {
        printf("\n1. Push  2. Pop  3. Show");
        printf("\nPlease choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        default:
            printf("Wrong choice!!");
            break;
        }
    } while (choice == 1 || choice == 2 || choice == 3);

    return 0;
}