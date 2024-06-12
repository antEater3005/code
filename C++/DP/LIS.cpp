#include <bits/stdc++.h>
using namespace std;
int LIS_util(vector<int> &nums, int i, int prev)
{
    if (i == nums.size())
        return 0;
    int len = LIS_util(nums, i + 1, prev);
    if (prev == -1 || nums[i] > nums[prev])
        len = max(len, 1 + LIS_util(nums, i + 1, i));
    return len;
}
int LIS(vector<int> &nums)
{
    return LIS_util(nums, 0, -1);
}
int main()
{

    return 0;
}
class Solution
{
private:
    int LIS_util(vector<int> &nums, int i, int prev, vector<vector<int>> &memo)
    {
        if (i == nums.size())
            return 0;
        if (prev != -1 && memo[i][prev] != -1)
            return memo[i][prev];
        int len = memo[i][prev] = LIS_util(nums, i + 1, prev, memo);
        if (prev == -1 || nums[i] > nums[prev])
            memo[i][prev] = len = max(len, 1 + LIS_util(nums, i + 1, i, memo));
        return len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return LIS_util(nums, 0, -1, memo);
    }
};