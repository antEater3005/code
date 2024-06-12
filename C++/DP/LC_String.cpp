#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 0; i <= nums1.size(); i++)
        {
            for (int j = 0; j <= nums2.size(); j++)
            {
                if (i == 0 || j == 0)
                    continue;
                else if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}
/* Problems based on Longest common subsequence*/
/**  516. Longest Palindromic Subsequence
 https://leetcode.com/problems/longest-palindromic-subsequence/ */
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string a(s.size(), '$');
        reverse_copy(s.begin(), s.end(), a.begin());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
            for (int j = 0; j <= s.size(); j++)
                if (i == 0 || j == 0)
                    continue;
                else if (s[i - 1] == a[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return dp[s.size()][s.size()];
    }
};

/* 647. Palindromic Substrings */

class Solution
{
private:
    int palindrome(string &s, int i, int j)
    {
        int count = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j])
            count++, i--, j++;
        return count;
    }

public:
    int countSubstrings(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            ans += palindrome(s, i, i) + palindrome(s, i, i + 1);
        return ans;
    }
};

/*  1312. Minimum Insertion Steps to Make a String Palindrome   */
class Solution
{
public:
    int minInsertions(string s)
    {
        string a(s.size(), '$');
        reverse_copy(begin(s), end(s), begin(a));
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++)
            for (int j = 0; j <= s.size(); j++)
                if (i == 0 || j == 0)
                    continue;
                else if (s[i - 1] == a[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        return s.size() - dp[s.size()][s.size()];
    }
};

class Solution
{
private:
    string supersubsequence(string a, string b)
    {
        string ans = "";
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

        for (int i = 0; i <= a.size(); i++)
            for (int j = 0; j <= b.size(); j++)
                if (i == 0 || j == 0)
                    continue;
                else if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        int i = a.size(), j = b.size();
        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
                ans += a[i - 1], i--, j--;
            else if (dp[i - 1][j] > dp[i][j - 1])
                ans += a[i - 1], i--;
            else
                ans += b[j - 1], j--;
        }
        while (j > 0)
            ans += b[j-- - 1];
        while (i > 0)
            ans += a[i-- - 1];
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    string shortestSuperstring(vector<string> &words)
    {
        string ans = words[0];
        for (int i = 1; i < words.size(); i++)
            ans = supersubsequence(ans, words[i]);
        return ans;
    }
};

class Solution
{
public:
    int numDistinct(string a, string b)
    {
        vector<double> curr(b.size() + 1, 0), prev(b.size() + 1, 0);
        curr[0] = prev[0] = 1;
        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= b.size(); j++)
            {
                if (a[i - 1] == b[j - 1])
                    prev[j] = curr[j - 1] + curr[j];
                else
                    prev[j] = curr[j];
            }
            curr = prev;
        }
        return (int)curr[b.size()];
    }
};
