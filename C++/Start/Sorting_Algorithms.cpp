#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
    }
}
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int t = a[i]; // this is the number to be inserted.
        int j = i;
        while (j > 0 && a[j - 1] > t)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}
int main()
{
    int arr[] = {34, 43, 54, 65, 2, 34, 8};

    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
    // BubbleSort(arr, 7);
    // InsertionSort(arr, 7);
    SelectionSort(arr, 7);
    for (auto a : arr)
    {
        cout << a << " ";
    }
    return 0;
}