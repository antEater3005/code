#include <iostream>
using namespace std;
int freindsPairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }
    return freindsPairing(n - 1) + freindsPairing(n - 2) * (n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << freindsPairing(n);
    return 0;
}