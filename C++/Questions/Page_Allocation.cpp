/*Allocate minimum number of pages 
Difficulty:Hard
  You are given N number of books. Every ith book has A[i] number of pages. 
  You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. */
//   Link:-https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
#include <iostream>
using namespace std;
int maximum(int arr[], int n, int m)
{
    if (n < m)
        return -1;
    int low = arr[0], high = arr[0];
    for (int i = 1; i < n; i++)
    {
        low = max(low, arr[i]);
        high += arr[i];
    }
    int ans = -1;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        int sum = 0;
        int std = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                sum = arr[i];
                std += 1;
            }
        }
        if (std == m)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (std < m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int arr[] = {250, 10, 30, 40};
    int n = 4, m = 3;
    cout << maximum(arr, n, m);
}