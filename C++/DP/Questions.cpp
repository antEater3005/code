#include <bits/stdc++.h>
using namespace std;
// 72. Edit Distance
// recursive solution
class Solution
{
private:
    int f(string &a, string &b, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (a[i] == b[j])
            return f(a, b, i - 1, j - 1);
        int _delete = 1 + f(a, b, i - 1, j);
        int _insert = 1 + f(a, b, i, j - 1);
        int _replace = 1 + f(a, b, i - 1, j - 1);
        return min(_delete, min(_insert, _replace));
    }

public:
    int minDistance(string word1, string word2)
    {
        return f(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};

// memoization
class Solution
{
private:
    int f(string &a, string &b, int i, int j, vector<vector<int>> &memo)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (a[i] == b[j])
            return memo[i][j] = f(a, b, i - 1, j - 1, memo);
        int _delete = 1 + f(a, b, i - 1, j, memo);
        int _insert = 1 + f(a, b, i, j - 1, memo);
        int _replace = 1 + f(a, b, i - 1, j - 1, memo);
        return memo[i][j] = min(_delete, min(_insert, _replace));
    }

public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
        return f(word1, word2, word1.size() - 1, word2.size() - 1, memo);
    }
};

// bottom up
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int i = 0; i <= word2.size(); i++)
            dp[0][i] = i;
        for (int i = 1; i <= word1.size(); i++)
            for (int j = 1; j <= word2.size(); j++)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
        return dp[word1.size()][word2.size()];
    }
};
// space optimized bottom up
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        vector<int> curr(word2.size() + 1), prev(word2.size() + 1);

        for (int i = 0; i <= word2.size(); i++)
            prev[i] = i;
        for (int i = 1; i <= word1.size(); i++)
        {
            curr[0] = i;
            for (int j = 1; j <= word2.size(); j++)
                if (word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(prev[j - 1], min(curr[j - 1], prev[j]));
            prev = curr;
        }
        return prev[word2.size()];
    }
};

// 44. Wildcard Matching

class Solution
{
private:
    bool match(string &s, string &p, int i, int j, vector<vector<int>> &memo)
    {
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0)
        {
            for (j; j >= 0; j--)
                if (p[j] != '*')
                    return false;
            return true;
        }
        if (memo[i][j] != -1)
            return memo[i][j];
        if (p[j] == '?' || p[j] == s[i])
            return memo[i][j] = match(s, p, i - 1, j - 1, memo);
        else if (p[j] == '*')
            return memo[i][j] = match(s, p, i, j - 1, memo) || match(s, p, i - 1, j, memo);
        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> memo(s.size(), vector<int>(p.size(), -1));
        return match(s, p, s.size() - 1, p.size() - 1, memo);
    }
};

// Bottom up approach
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        bool flag = true;
        for (int i = 1; i <= p.size(); i++)
        {
            if (p[i - 1] != '*')
                flag = false;
            dp[0][i] = flag;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
        }
        return dp[s.size()][p.size()];
    }
};

// Bottom up space optimized

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<bool> prev(p.size() + 1, false), curr(p.size() + 1, false);
        prev[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            bool flag = true;
            for (int k = 1; k <= p.size(); k++)
            {
                if (p[k - 1] != '*')
                    flag = false;
                prev[k] = flag;
            }
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                    curr[j] = curr[j - 1] || prev[j];
            }
            prev = curr;
        }
        return prev[p.size()];
    }
};

// 122. Best Time to Buy and Sell Stock II

class Solution
{
    int ans(vector<int> &prices, int canbuy, int i, vector<vector<int>> &memo)
    {
        if (i == prices.size())
            return 0;
        if (memo[canbuy][i] != -1)
            return memo[canbuy][i];
        int profit = 0;
        if (canbuy)
            profit = memo[canbuy][i] = max(-prices[i] + ans(prices, 0, i + 1, memo), ans(prices, 1, i + 1, memo));
        else
            profit = memo[canbuy][i] = max(prices[i] + ans(prices, 1, i + 1, memo), ans(prices, 0, i + 1, memo));
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> memo(3, vector<int>(prices.size() + 1, -1));
        return ans(prices, 1, 0, memo);
    }
};

// botttom up

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        dp[prices.size()][0] = dp[prices.size()][1] = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);

            dp[i][0] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
        }
        return dp[0][1];
    }
};

// 123. Best Time to Buy and Sell Stock III
// recursive solution

class Solution
{
    int maxiProfit(vector<int> &prices, int canbuy, int i, int transactions)
    {
        if (transactions == 0 || i == prices.size())
            return 0;
        int profit = 0;
        if (canbuy)
            profit = max(-prices[i] + maxiProfit(prices, 0, i + 1, transactions), maxiProfit(prices, 1, i + 1, transactions));
        else
            profit = max(prices[i] + maxiProfit(prices, 1, i + 1, transactions - 1), maxiProfit(prices, 0, i + 1, transactions));
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        return maxiProfit(prices, 1, 0, 2);
    }
};

// Memoization

class Solution
{
    int maxiProfit(vector<int> &prices, int canbuy, int i, int transactions, vector<vector<vector<int>>> &memo)
    {
        if (transactions == 0 || i == prices.size())
            return 0;
        if (memo[i][canbuy][transactions] != -1)
            return memo[i][canbuy][transactions];
        int profit = 0;
        if (canbuy)
            memo[i][canbuy][transactions] = profit = max(-prices[i] + maxiProfit(prices, 0, i + 1, transactions, memo), maxiProfit(prices, 1, i + 1, transactions, memo));
        else
            memo[i][canbuy][transactions] = profit = max(prices[i] + maxiProfit(prices, 1, i + 1, transactions - 1, memo), maxiProfit(prices, 0, i + 1, transactions, memo));
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return maxiProfit(prices, 1, 0, 2, memo);
    }
};

// Bottom up

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 1; j <= 2; j++)
            {
                dp[i][1][j] = max(-prices[i] + dp[i + 1][0][j], dp[i + 1][1][j]);
                dp[i][0][j] = max(prices[i] + dp[i + 1][1][j - 1], dp[i + 1][0][j]);
            }
        }
        return dp[0][1][2];
    }
};

int main()
{

    return 0;
}
class Solution
{
private:
    int maxiProfit(vector<int> &prices, int canbuy, int i, int transactions, vector<vector<vector<int>>> &memo)
    {
        if (transactions == 0 || i == prices.size())
            return 0;
        if (memo[i][transactions][canbuy] != -1)
            return memo[i][transactions][canbuy];
        int profit = 0;
        if (canbuy)
            memo[i][transactions][canbuy] = profit = max(-prices[i] + maxiProfit(prices, 0, i + 1, transactions, memo), maxiProfit(prices, 1, i + 1, transactions, memo));
        else
            memo[i][transactions][canbuy] = profit = max(prices[i] + maxiProfit(prices, 1, i + 1, transactions - 1, memo), maxiProfit(prices, 0, i + 1, transactions, memo));

        return profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(k+1, vector<int>(2, -1)));
        return maxiProfit(prices, 1, 0, k, memo);
    }
};