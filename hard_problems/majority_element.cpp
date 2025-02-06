// Given an array of size N, find the majority element.
// A majority element appears more than N/2 times in the array.
// If there is no majority element, return -1.

// Example:
// Input: arr = {3, 3, 4, 2, 4, 4, 2, 4, 4}
// Output: 4
// Input: arr = {3, 3, 4, 2, 4, 4, 2, 4}
// Output: -1

#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int> &arr)
{
    int count = 0, candidate = -1;

    for (int num : arr)
    {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }

    // Verify if the candidate is actually the majority element
    count = 0;
    for (int num : arr)
    {
        if (num == candidate)
            count++;
    }

    return (count > arr.size() / 2) ? candidate : -1;
}

int main()
{
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << findMajorityElement(arr) << endl; // Output: 4
    return 0;
}
