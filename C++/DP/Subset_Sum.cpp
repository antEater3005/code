// In this problem an integer array and a targetSum is given we have to find wether there is any subset of array having sum equal to the targetsum;
#include <bits/stdc++.h>
using namespace std;
// Recursive approach
bool IsSubset(vector<int> arr, int targetSum, int size)
{
    if (targetSum == 0)
        return true;
    if (size == 0)
        return false;
    if (targetSum < arr[size - 1])
        return IsSubset(arr, targetSum, size - 1);
    else
        return IsSubset(arr, targetSum - arr[size - 1], size - 1) || IsSubset(arr, targetSum, size - 1);
}
// Recursion with memoization
bool isSubsetUtil(vector<int> arr, int targetSum, int size, vector<vector<bool>> &memo)
{
    if (targetSum == 0)
        return true;
    if (size == 0)
        return false;
    if (memo[size - 1][targetSum])
        return true;
    if (arr[size - 1] > targetSum)
        return memo[size - 1][targetSum] = isSubsetUtil(arr, targetSum, size - 1, memo);
    else
        return memo[size - 1][targetSum] = isSubsetUtil(arr, targetSum, size - 1, memo) || isSubsetUtil(arr, targetSum - arr[size - 1], size - 1, memo);
}
bool isSubset2(vector<int> arr, int targetSum, int size)
{
    vector<vector<bool>> memo(size + 1, vector<bool>(targetSum + 1, false));
    return isSubsetUtil(arr, targetSum, size, memo);
}
// The above solution gives TLE on GFG which have time limit of 1.01 sec;
// Now we see the top-down approach of the above problem
bool isSubsetTD(vector<int> arr, int size, int targetSum)
{
    int memo[size + 1][targetSum + 1];
    for (int i = 0; i < size + 1; i++)
        memo[i][0] = 0; // setting the initial values of the array to 1: because the first column of the array represent the targetSum of 0 so we can always make a subset with sum 0 i.e., by not adding any element;
    for (int i = 1; i < targetSum + 1; i++)
        memo[0][i] = false; // By the same logic we cannot make any subset with non-zero sum because the first row represents an empty array: So we initialise the first row with false;
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < targetSum + 1; j++)
        {
            if (arr[i - 1] > j)
                memo[i][j] = memo[i - 1][j];
            else
                memo[i][j] = memo[i - 1][j] || memo[i - 1][j - arr[i - 1]];
        }
    }
    return memo[size][targetSum]; // return the ans;
}
// Equal Sum Partition problem: this function checks whether the given array can be divided into two subsets of equal partition;
bool EqualSumPartition(vector<int> arr, int size)
{
    int sum = 0;
    for (auto a : arr)
        sum += a;
   
    if (sum % 2 == 1)
        return false;
    else
        return isSubsetTD(arr, size, sum / 2);
}
int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int targetSum = 14, size = arr.size();
    cout << EqualSumPartition(arr, size);
    return 0;
}