// This function gives the number of subsets of sum equal to a given sum;
#include <bits/stdc++.h>
using namespace std;
int numberOfSubset(vector<int> arr, int sum)
{
    int n = arr.size();
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < sum + 1; i++)
        t[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            else
                t[i][j] = t[i - 1][j];
    return t[n][sum];
}
int numberOfSubset2(vector<int> arr, int sum) // Not working properly
{
    vector<int> t(sum + 1, 0);
    t[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = sum; j >= arr[i]; j--)
            t[j] = t[j] + t[j - arr[i]];
    }
    return t[sum];
}
int main()
{
    vector<int> a = {4, 3, 2, 3, 5, 2, 1};
    int sum = 4;
    cout << numberOfSubset2(a, 10);
    return 0;
}