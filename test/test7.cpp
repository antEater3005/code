
// Given a number (as string) and two integers a and b, divide the string in two non-empty parts such that the first part is divisible by a and the second part is divisible by b. In case multiple answers exist, return the string such that the first non-empty part has minimum length.
// Link:https://practice.geeksforgeeks.org/problems/partition-a-number-into-two-divisible-parts3605/1#
#include <bits/stdc++.h>
using namespace std;
string stringPartition(string S, int a, int b)
{
    int left = S[0] - '0';
    for (int i = 1; i < S.length(); i++)
    {

        if (left % a == 0)
        {
            int right = 0, j = i;
            while (j < S.length())
            {
                right = right * 10 + S[j] - '0';
                j++;
            }
            if (right % b == 0)
                return S.substr(0, i) + " " + S.substr(i, j);
        }
        left = left * 10 + S[i] - '0';
    }
    return "-1";
}
/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.*/
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    int dp[n][n];
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            int maxCoin = INT_MIN;
            for (int k = i; k <= j; k++)
            {
                int left = k == i ? 0 : dp[i][k - 1];
                int right = k == j ? 0 : dp[k + 1][j];
                int val = (i == 0 ? 1 : nums[i - 1]) * nums[k] * (j == n - 1 ? 1 : nums[j + 1]);
                int total = left + right + val;
                maxCoin = max(maxCoin, total);
            }
            dp[i][j] = maxCoin;
        }
    }
    return dp[0][n - 1];
}
int main()
{
    string s = "5010";
    cout << stringPartition(s, 10, 10);

    return 0;
}