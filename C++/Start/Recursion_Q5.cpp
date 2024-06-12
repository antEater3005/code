//TO CHECK IF AN ARRAY IS SORTED OR NOT.
//ARRAY IS INCREASING OR NOT.
#include <iostream>
using namespace std;
bool check(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    bool restarr = check(arr + 1, n - 1);
    return (arr[0] < arr[1] && restarr);
}
int main()
{
    int arr[] = {1, 2, 3,45, 5, 6, 7, 8, 9};
    cout << check(arr, 9) << endl;
    return 0;
}