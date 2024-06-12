// Description:You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
#include <bits/stdc++.h>
using namespace std;
// This Problem is same as the  given_difference_subset problem here the target is same as the difference in the earlier problem;
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = (accumulate(nums.begin(), nums.end(), 0) + target) / 2;
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = true;
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = false;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (nums[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}
int main()
{
    vector<int> nums = {0, 0, 0, 0, 0, 0, 7, 7, 1};
    int target = 1;
    cout << findTargetSumWays(nums, target);
    return 0;
}