// Full form of DNF is Dutch National Flag, also known as 0,1,2 sort.
#include <iostream>
using namespace std;
void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void dnfSort(int arr[], int n)
{
    int mid = 0;
    int high = n - 1;
    int low = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, low, mid);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr, mid, high);
            high++;
        }
    }
}
int main()
{
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    dnfSort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}