  //Kadane's algorithm is used find the max sum subarray in a array.
#include <bits/stdc++.h>
using namespace std;
int kadane_algo(int arr[], int n)
{
    int best_sum = arr[0], curr_sum = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (curr_sum >= 0)
        {
            curr_sum = curr_sum + arr[i];
        }
        else
        {
            curr_sum = arr[i];
        }
        if (curr_sum > best_sum)
        {
            best_sum = curr_sum;
        }
    }
    return best_sum;
}
int main()
{
    int n = 7;
    int arr[] = {-99,-21,-1, -2, -3, -2, -5};
    int ans = kadane_algo(arr, n);
    cout << ans;

    return 0;
}