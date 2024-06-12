#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 3, 4}, in(3, 0);

    return 0;
}

class Solution
{
    int dp[3][1001][1001];
    int wiggle(vector<int> &nums, int sign, int index, int prev)
    {
        if (index == nums.size())
            return 0;
        if (dp[sign][prev][index] != -1)
            return dp[sign][prev][index];
        if ((sign == 1 && nums[index] > prev) || (sign == 2 && nums[index] < prev))
            return dp[sign][prev][index] = max(1 + wiggle(nums, sign == 1 ? 2 : 1, index + 1, nums[index]), wiggle(nums, sign, index + 1, prev));
        return dp[sign][prev][index] = wiggle(nums, sign, index + 1, prev);
    }

public:
    int wiggleMaxLength(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int ans = wiggle(nums, 1, 0, INT_MIN);
        memset(dp, -1, sizeof(dp));
        return max(ans, wiggle(nums, 2, 0, INT_MAX));
    }
};
#include <bits/stdc++.h>
using namespace std;
int sa(vector<pair<int, int>> &nums, int i)
{
    int left = 0, right = nums.size() - 1, ans = 0, idx = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[i].first * 2 >= nums[mid].first && ans < nums[mid].first)
            ans = nums[mid].first, idx = mid;
        if (nums[i].first * 2 > nums[mid].first)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (nums[idx].second == nums[i].second)
        return idx == 0 ? -1 : nums[i - 1].first;
    return nums[idx].first;
}
int main()
{
    int t, x = 0;
    cin >> t;
    while (x < t)
    {
        x++;
        int n;
        cin >> n;
        vector<pair<int, int>> nums(n), search;
        for (int i = 0; i < n; i++)
        {
            int z;
            cin >> z;
            nums[i] = {z, i};
        }
        vector<int> ans(n);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int t = sa(nums, nums[i].second);
            search.push_back({nums[i].second, t});
        }
        cout << "Case #" << x << ": ";
        for (auto it : search)
            cout << it.first << " " << it.second << endl;
        cout << endl;
    }
    return 0;
}