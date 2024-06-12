#include "bits/stdc++.h"
 

using namespace std;
long long count_XOR(int arr[], int n)
{
    sort(arr, arr + n);
    long long count = 1, sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {  
            sum += (count * (count - 1)) / 2;
            count = 1;
        }
    }
    if (arr[n - 2] == arr[n - 1])
    {
        sum += (count * (count - 1)) / 2;
    }
    return sum;
}
int main()
{
    int arr[]={2,4,6,3,4,6,1,4,7,8,3,1,2,2};
    cout<<count_XOR(arr,14);

   
    return 0;
}