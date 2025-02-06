// Problem Statement:
// Given a sorted array and a target element,
// find the first and last position of the target element.
// If the element is not found, return [-1, -1].

// Example:
// Input: arr = {5, 7, 7, 8, 8, 10}, target = 8
// Output: [3, 4]

// Example:
// Input: arr = {1, 2, 3, 4, 5}, target = 6
// Output: [-1, -1]

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target, bool findFirst)
{
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            if (findFirst)
                high = mid - 1; // Search left
            else
                low = mid + 1; // Search right
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return result;
}

vector<int> searchRange(vector<int> &arr, int target)
{
    return {binarySearch(arr, target, true), binarySearch(arr, target, false)};
}

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(arr, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [3, 4]
    return 0;
}
