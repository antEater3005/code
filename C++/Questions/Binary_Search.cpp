#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        // Here we find the mid element in the array.
        // int mid=(start+end)/2; // this is not a good method to find the middle element because (start+end) can have a value greater then the max element that it can store (Overflow occurs);
        // Instead we should use
        int mid = start + (end - start) / 2;

        if (target < arr[mid])
            end = mid - 1;
        else if (target > arr[mid])
            start = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 5, 8, 9, 14, 16, 19, 23, 56, 78, 89, 98, 100};
    int n = 13;
    int a = binarySearch(arr, n, 1236);
    if (a == -1)
        cout << "Element is not present.";
    else
    {
        cout << "The index of the element: " << a << endl;
    }
    return 0;   
}