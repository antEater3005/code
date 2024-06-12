#include <bits/stdc++.h>
using namespace std;

/** Link::https://leetcode.com/problems/longest-common-subsequence/ */

class recursive
{
    void LCS(string &a, string &b, int i, int j, int &ans, int s)
    {
        if (i == 0 || j == 0)
        {
            ans = max(ans, s);
            return;
        }
        if (a[i] == b[j])
            LCS(a, b, i - 1, j - 1, ans, s + 1);
        LCS(a, b, i - 1, j, ans, s);
        LCS(a, b, i, j - 1, ans, s);
    }

public:
    int longestCommonSubsequence(string a, string b)
    {
        int ans = 0;
        LCS(a, b, a.size() - 1, b.size() - 1, ans, 0);
    }
};

/**  Recursion + Memoization */
class Solution
{
private:
    int LCS(string &a, string &b, int i, int j, vector<vector<int>> &t)
    {
        if (i < 0 || j < 0)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];
        if (a[i] == b[j])
            return t[i][j] = 1 + LCS(a, b, i - 1, j - 1, t);
        else
            return t[i][j] = max(LCS(a, b, i - 1, j, t), LCS(a, b, i, j - 1, t));
        return t[0][0];
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return LCS(text1, text2, text1.size() - 1, text2.size() - 1, memo);
    }
};

/**Top-Down*/
class top_down
{
public:
    int longestCommonSubsequence(string a, string b)
    {
        vector<vector<int>> memo{a.size() + 1, vector<int>(b.size() + 1, -1)};
        for (int i = 0; i <= a.size(); i++)
        {
            for (int j = 0; j <= b.size(); j++)
            {
                if (i == 0 || j == 0)
                    memo[i][j] = 0;
                else if (a[i - 1] == b[j - 1])
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                else
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
        int n = memo[a.size()][b.size()]; // its stores the length of longest common subsequence
        string ans(n, '0');               // stores the longest common subsequence
        int idx = n - 1, i = a.size(), j = b.size();
        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1]) // if character are same it means it is part of subsequence so add it into the ans string
            {
                cout << idx << " ";
                ans[idx] = a[i - 1];
                idx--, i--, j--;
            }
            else // we go to the maximum of the longest length using memo
            {
                if (memo[i][j - 1] > memo[i - 1][j])
                    j--;
                else
                    i--;
            }
        }
        cout << ans;
        return n;
    }
};
int main()
{

    return 0;
}
