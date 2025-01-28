#include <iostream>
#include <vector>

using namespace std;
void backtrack(vector<int> &candidates, int target, vector<int> &path, vector<vector<int>> &result, int start)
{

    if (target == 0)
    {
        result.push_back(path);
        return;
    }

    if (target < 0)
    {
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        path.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], path, result, i);
        path.pop_back();
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
    vector<int> candidates = {2, 3, 6, 7};

    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations: " << endl;

    for (const auto &combination : result)
    {
        cout << "[";
        for (size_t i = 0; i < combination.size(); i++)
        {
            cout << combination[i];
            w
        }
        cout << "]" << endl;
    }

    return 0;
}