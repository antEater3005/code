#include <iostream>
using namespace std;
int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i + 1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = lastocc(arr, n, i + 1, key);
    if (restArray != -1)
    {
        return restArray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 25, 1, 5, 7, 6, 3, 5, 4, 8, 10};
    int key;
    cin >> key;
    cout << firstocc(arr, 11, 0, key) << endl;
    cout << lastocc(arr, 11, 0, key) << endl;
    return 0;
}
