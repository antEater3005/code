// In unbounded knapsack there are multiple occurrences of a single item ;
// An item is not marked as processed until it's declined at some point of time.
#include <bits/stdc++.h>
using namespace std;
// 1. Unbounded Knapsack:Solution using recursion
int unbounded_knapsack(vector<int> weight, vector<int> value, int size, int capacity)
{
    if (size == 0 || capacity == 0)
        return 0;
    if (weight[size - 1] <= capacity)
        return max(value[size - 1] + unbounded_knapsack(weight, value, size, capacity - weight[size - 1]),
                   unbounded_knapsack(weight, value, size - 1, capacity));
    else
        return unbounded_knapsack(weight, value, size - 1, capacity);
}
// 2. Solution using recursion and memoization
// helper function:
int unbounded_knapsack_memo_util(vector<int> weight, vector<int> values, int size, int capacity, vector<vector<int>> &memo)
{
    if (size == 0 || capacity == 0)
        return 0;
    if (memo[size - 1][capacity] != -1)
        return memo[size - 1][capacity];
    if (weight[size - 1] <= capacity)
        return memo[size - 1][capacity] = max(values[size - 1] + unbounded_knapsack_memo_util(weight, values, size, capacity - weight[size - 1], memo), unbounded_knapsack_memo_util(weight, values, size - 1, capacity, memo));
    else
        return memo[size - 1][capacity] = unbounded_knapsack_memo_util(weight, values, size - 1, capacity, memo);
}
// main function:
int unbounded_knapsack_memo(vector<int> weight, vector<int> values, int size, int capacity)
{
    vector<vector<int>> memo(size + 1, vector<int>(capacity + 1, -1));
    return unbounded_knapsack_memo_util(weight, values, size, capacity, memo);
}
// Top-Down approach:
int unbounded_knapsack_topDown(vector<int> weight, vector<int> values, int size, int capacity) // incomplete
{
    int memo[capacity + 1];
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < capacity + 1; i++)
        for (int j = 0; j < size; j++)
            if (weight[j] <= i)
                memo[i] = max(memo[i], values[j] + memo[i - weight[j]]);

    return memo[capacity];
}
/**Rod cutting problem Variation of unbounded knapsack */
int cutRod3(int price[], int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], price[j] + dp[i - j]);
    return dp[n];
}
int cutRod(int price[], int n)
{
    // code here
    int length[n];
    for (int i = 0; i < n; i++)
        length[i] = i + 1;
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (length[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - length[i - 1]]);
        }
    }
    return dp[n][n];
}
int main()
{

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price, 8);
    return 0;
}