#include <bits/stdc++.h>
using namespace std;
// 0/1 knapsack problem:The knapsack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible
// Recursive function
int knapSack1(vector<int> weight, vector<int> value, int capacity, int n)
{
    if (n == 0 || capacity == 0) // base case
        return 0;
    if (weight[n - 1] <= capacity)
        return max(value[n - 1] + knapSack1(weight, value, capacity - weight[n - 1], n - 1), knapSack1(weight, value, capacity, n - 1));
    else if (weight[n - 1] > capacity)
        return knapSack1(weight, value, capacity, n - 1);
}
// Knapsack problem using recursion and memoization
int knapSackUtil(vector<int> weight, vector<int> value, int capacity, int n, vector<vector<int>> &memo)
{
    if (n == 0 || capacity == 0) // base case
        return 0;
    if (memo[n - 1][capacity] != -1) // before calling the function again we check for the values computed earlier if present then return the value;
        return memo[n - 1][capacity];
    if (weight[n - 1] <= capacity)
        return memo[n - 1][capacity] = max(value[n - 1] + knapSackUtil(weight, value, capacity - weight[n - 1], n - 1, memo), knapSackUtil(weight, value, capacity, n - 1, memo)); // we store the calculated value in memo.
    else if (weight[n - 1] > capacity)
        return memo[n - 1][capacity] = knapSackUtil(weight, value, capacity, n - 1, memo); // we store the calculated value in memo.
}
int knapSack2(vector<int> weight, vector<int> value, int capacity, int n)
{
    vector<vector<int>> memo(n + 1, vector<int>(capacity + 1, -1)); // initialization of memo having the constraints of having only 100 items and weight capacity of 150;
    return knapSackUtil(weight, value, capacity, n, memo);
}

// Top-Down Approach
int knapSackTD(vector<int> weight, vector<int> value, int capacity, int n)
{
    int memo[n + 1][capacity + 1];
    for (int i = 0; i < n + 1; i++)
        memo[i][0] = 0;
    for (int j = 0; j < capacity + 1; j++)
        memo[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (weight[i - 1] <= j)
            {
                memo[i][j] = max(value[i - 1] + memo[i - 1][j - weight[i - 1]], memo[i - 1][j]);
            }
            else
            {
                memo[i][j] = memo[i - 1][j];
            }
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    return memo[n][capacity];
}

int main()
{
    vector<int> w = {1, 2, 3};
    vector<int> v = {60, 100, 120};
    int c = 5;
    int n = sizeof(v) / sizeof(v[0]);
    cout << "Maximum Profit is=" << knapSackTD(w, v, c, n);
    // cout <<endl<<w[-2];
    return 0;
}