#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(vector<int> nums, int targetSum, int n)
{
    int memo[n + 1][targetSum + 1];
    for (int i = 0; i < n + 1; i++)
        memo[i][0] = 1;
    for (int i = 1; i < targetSum + 1; i++)
        memo[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < targetSum + 1; j++)
            if (nums[i - 1] > j)
                memo[i][j] = memo[i - 1][j];
            else
                memo[i][j] = memo[i - 1][j] || memo[i - 1][j - nums[i - 1]];
    return memo[n][targetSum];
}
bool EqualSumPartition(vector<int> nums, int n)
{
    int sum = 0;
    for (auto a : nums)
        sum += a;
    if (sum % 2 == 1)
        return 0;
    else
        return isSubsetSum(nums, sum / 2, n);
}
bool EqualSumPartitionSubset(vector<int> nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / 2;
    if (sum % 2 == 1)
        return false;
    vector<bool> t(target + 1, false);
    t[0] = true;
    for (auto num : nums)
        for (int i = target; i >= num; i--)
            t[i] = t[i] || t[i - num];
    return t[target];
}
int main()
{
    vector<int> nums = {1,2,3,4};
    int size = nums.size();
    cout << EqualSumPartitionSubset(nums);
    return 0;
}