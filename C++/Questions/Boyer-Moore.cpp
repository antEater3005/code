// Boyer-Moore algorithm is also known as Majority vote algorithm.
// It find out the number having maximum repetition in list.
/**NOTE:: Here the majority element is defined as an element which occurs more than N/2 time in the list N=size of list*/
#include <iostream>
using namespace std;
int MajorityVote(int a[], int n)
{
    int candidate = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            candidate = a[i];
        if (candidate == a[i])
            count++;
        else
            count--;
    }
    return candidate;
}
int main()
{
    int a[] = {2, 3, 4, 5, 3, 3, 3, 2, 1, 3, 1, 1, 6, 3, 3, 23, 4, 5}; // the majority element is  .
    int n = 18;
    cout << MajorityVote(a, n);
    return 0;
}