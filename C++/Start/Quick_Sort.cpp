#include <iostream>
using namespace std;
int swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void (int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        (arr, l, pi - 1);
        (arr, pi + 1, r);
    }
}

int main()
{
    int arr[6] = {4, 8, 9, 6, 5, 7};
    (arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}