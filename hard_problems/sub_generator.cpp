#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> &numbers, vector<int> &subset, vector<vector<int>> &result, int index)
{
    // Base case: If we've considered all elements, add the subset to the result
    if (index == numbers.size())
    {
        result.push_back(subset);
        return;
    }

    subset.push_back(numbers[index]);
    // Include the current number in the subset
    backtrack(numbers, subset, result, index + 1);

    // Remove the last number to explore other possibilities
    subset.pop_back();
    // Exclude the current number and move to the next
    backtrack(numbers, subset, result, index + 1);
}

vector<vector<int>> generateSubset(vector<int> numbers)
{
    vector<vector<int>> result;
    vector<int> subset;
    backtrack(numbers, subset, result, 0); // Start from index 0
    return result;
}

int main()
{
    vector<int> numbers = {1, 2, 3};
    // Output: [[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]

    vector<vector<int>> result = generateSubset(numbers);

    cout << "Subsets: " << endl;

    for (const auto &subset : result)
    {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
