
                                           /*  ***********************************************************
                                               ***********************************************************
                                                              DYNAMIC PROGRAMMING
                                                           USING MEMOIZATION AND RECURSION
                                               ***********************************************************
                                               *********************************************************** */

#include "bits/stdc++.h"
using namespace std;
long long calls = 0;
int fib[40];
// Fibonacci number using the memoization which makes the Time Complexity of O(N);
long long int fibonacci(int n)
{
    calls++;
    if (n <= 1)
        return n;
    if (fib[n] != 0)
        return fib[n];
    fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib[n];
}

long long int gridtraveller(int a, int b)
{
    if (a == 1 || b == 1)
        return 1;

    return gridtraveller(a - 1, b) + gridtraveller(a, b - 1);
}
// CanSum: this function which find weather a target can be achieved by suming up the numbers in array multiple times;
// 1-> we can use the numbers multiple times.
// 2-> All the numbers in array are non-negative.
// Array SumArray is used fo memoization;
bool SumArray[300];
bool CanSum(int target, int arr[], int size)
{
    if (SumArray[target])
        return true;
    if (target == 0)
        return true;
    if (target < 0)
        return false;
    for (int i = 0; i < size; i++)
    {
        int temp = target - arr[i];
        if (CanSum(temp, arr, size))
        {
            SumArray[target] = true;
            return true;
        }
    }
    SumArray[target] = false;
    return false;
}
bool HowSum(int target, int arr[], int size, vector<int> &ans)
{
    if (target == 0)
    {
        return true;
    }
    if (target < 0)
        return false;
    for (int i = 0; i < size; i++)
    {

        int newTarget = target - arr[i];

        bool ss = HowSum(newTarget, arr, size, ans);
        if (ss)
        {
            ans.push_back(arr[i]);
            return true;
        }
    }
    return false;
}
void help(int n,string  &a)
{
    a.erase(0, n);
}
bool  CCUtility(string a, string b)
{

    for (int j = 0; j < a.size(); j++)
    {
        if (a[j] != b[j])
            return false ;
    }
     
    return true;
}
bool canConstruct(string target, vector<string> wordbank)
{
    if (target == "")
        return true;

    for (int i = 0; i < wordbank.size(); i++)
    {
        if (CCUtility(wordbank[i], target))
        {
            help(wordbank[i].size(), target);
             return canConstruct(target, wordbank);
        }
         
       
    }
    return false;
}
int main()
{
    // cout << gridtraveller(1, 1) << " ";
    // cout << gridtraveller(3, 3) << " ";
    // cout << gridtraveller(18, 18) << " ";
    // int n = 41;

    // for (int i = 0; i < n; i++)
    //     fib[i] = 0;
    // cout << fibonacci(n);
    // int target = 300;
    // vector<bool> Sum(target, false);
    // //  SumArray=Sum;
    // for (int i = 0; i < target; i++)
    //     SumArray[i] = false;
    // int arr[2] = {7, 14};
    // if (CanSum(target, arr, 2))
    // {
    //     cout << "True";
    // }
    // else
    // //     cout << "False";
    // string tar = "abcdef";
    // vector<string> word = {"ab", "bc", "abc", "cd", "de"};
    // if (canConstruct(tar, word))
    // {
    //     cout << "True";
    // }
    // else
    //     cout << "False";
    int arr[]={2,4,1,6,3};
    

    return 0;
}