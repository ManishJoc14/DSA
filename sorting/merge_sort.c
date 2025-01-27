#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // size of left array
    int n2 = r - m;     // size of right array

    int L[n1], R[n2]; // Create copies of the subarrays

    for (i = 0; i < n1; i++) // copy data to the subarrays
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++) // copy data to the subarrays
        R[j] = arr[m + 1 + j];

    // Maintain current index of sub-arrays and main array
    i = 0;
    j = 0;
    k = l;

    // Until we reach either end of either L or M, pick larger among
    // elements L and R and place them in the correct position at A[l..r]

    while (i < n1 && j < n2)
    {
        // merge temp arrays back into arr
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or R,
    // pick up the remaining elements and put in A[l..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {1, 5, 3, 4, 2, 6, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("-------------------------Merge Sort-------------------------");
    printf("\nBefore sorting: ");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    merge_sort(arr, 0, arr_size - 1);

    printf("\nAfter  sorting: ");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    return 0;
}