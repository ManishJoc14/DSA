#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target)
{
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;

        // found
        if (arr[m] == target)
            return m;

        if (arr[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1; // element not found
}

// Perform bubble sort
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter target: ");
    scanf("%d", &target);

    // Sort the array
    bubbleSort(arr, size);

    // Perform binary search
    int result = binarySearch(arr, size, target);

    printf("Given elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    if (result != -1)
        printf("\n%d found at index %d\n", target, result);
    else
        printf("\n%d not found\n", target);

    return 0;
}
