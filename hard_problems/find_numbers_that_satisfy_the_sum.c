#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printCombination(int *comb, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", comb[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

void findCombinations(int *arr, int n, int target, int index, int *comb, int combSize)
{
    if (target == 0)
    {
        printCombination(comb, combSize);
        return;
    }

    for (int i = index; i < n; i++)
    {
        // Skip duplicates
        if (i > index && arr[i] == arr[i - 1])
            continue;

        if (arr[i] <= target)
        {
            comb[combSize] = arr[i];
            findCombinations(arr, n, target - arr[i], i + 1, comb, combSize + 1);
        }
    }
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    qsort(arr, n, sizeof(int), compare); // Sort the array to handle duplicates
    int comb[n];

    printf("Combinations:\n");
    findCombinations(arr, n, target, 0, comb, 0);

    return 0;
}
