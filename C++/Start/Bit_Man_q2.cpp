#include <iostream>
using namespace std;
int numberofones(long long int n)
{
   long long  int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    long long int n;
    cin >> n;
    cout << numberofones(n);
    return 0;
}