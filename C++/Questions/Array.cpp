#include "bits/stdc++.h"
using namespace std;
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
// Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
void rearrange(long long *arr, int n)
{
    int min = 0, max = n - 1, me = arr[n - 1] + 1; // me is the maximum element in the array
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += ((arr[max] % me) * me);
            max--;
        }
        else
        {
            arr[i] += ((arr[min] % me) * me);
            min++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / me;
    }
}
//Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=1&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]1page1category[]Arrays#
int maxPF(int arr[], int dep[], int n)
{
    int temp[2400] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
        temp[dep[i] + 1]--;
    }
    int maxPf = 0;
    for (int i = 1; i < 2400; i++)
    {
        temp[i] += temp[i - 1];
        maxPf = max(temp[i], maxPf);
    }
    return maxPf;
}
// 1798. Maximum Number of Consecutive Values You Can Make  https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
//Hint::If you can make numbers till n and given a number v such that n+1<=v then we can make all the numbers less than and equal to n+v;
int getMaximumConsecutive(vector<int> &coins)
{
    sort(coins.begin(), coins.end());
    for (int i = 1; i < coins.size(); i++)
    {
        if (coins[i] <= coins[i - 1] + 1)
        {
            coins[i] += coins[i - 1];
        }
        else
            return coins[i - 1] + 1;
    }
    return coins[0] == 1 ? coins[coins.size() - 1] + 1 : 1;
}

// 73. Set Matrix Zeroes    https://leetcode.com/problems/set-matrix-zeroes/
/**space complexity::O(n+m)
        time complexity::O(n*m)*/
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<bool> arr_i(n, 0);
    vector<bool> arr_j(m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0)
            {
                arr_i[i] = 1;
                arr_j[j] = 1;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr_i[i] || arr_j[j])
                matrix[i][j] = 0;
    return;
}
/**constant space solution*/
void setZeroes2(vector<vector<int>> &matrix)
{
    bool row = 0, col = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
             if (i == 0 && matrix[i][j] == 0)
                col = 1;
            if (j == 0 && matrix[i][j] == 0)
                row = 1;
        }
    }
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (row)
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    if (col)
        for (int j = 0; j < matrix[0].size(); j++)
            matrix[0][j] = 0;
}
int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    // int arr[] = {1, 2, 3, 4, 5, 6};
    return 0;
}