// Given an array nums and an integer target,
// return indices of the two numbers such that they add up to target.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if (seen.find(diff) != seen.end())
        {
            return {seen[diff], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
