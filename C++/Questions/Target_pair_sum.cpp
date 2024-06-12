/*You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.*/
#include <bits/stdc++.h>
using namespace std;

int numPairsDivisibleBy60(vector<int> &time)
{
    int ans = 0;
    int t[60] = {0};
    for (int i = 0; i < time.size(); i++)
    {
        if (t[(60 - time[i] % 60) % 60] != 0)
            ans += t[(60 - time[i] % 60) % 60];
        t[time[i] % 60] += 1;
    }
    return ans;
}
// https://leetcode.com/problems/find-the-town-judge/

int findJudge(int n, vector<vector<int>> &trust)
{
    vector<int> arr(n, 0);
    for (int i = 0; i < trust.size(); i++)
    {
        arr[trust[i][0] - 1]--;
                                    arr[trust[i][0] - 1]++;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] == n - 1)
            return i + 1;
    return -1;
}
int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}};

    cout << findJudge(3, v);
    return 0;
}