#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &candidates, int target, vector<int> &path, vector<vector<int>> &result, int start)
{
    if (target == 0)
    {
        result.push_back(path); // Add valid combination to the result
        return;
    }
    if (target < 0)
        return; // Stop further exploration if the target becomes negative

    for (int i = start; i < candidates.size(); i++)
    {
        path.push_back(candidates[i]);                                  // Choose the current element
        backtrack(candidates, target - candidates[i], path, result, i); // Recurse with updated target
        path.pop_back();                                                // Backtrack to explore other options
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> path;
    backtrack(candidates, target, path, result, 0);
    return result;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7}; // Example input
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations:" << endl;
    for (const auto &combination : result)
    {
        cout << "[";
        for (size_t i = 0; i < combination.size(); i++)
        {
            cout << combination[i];
            if (i < combination.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
