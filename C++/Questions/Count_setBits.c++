#include "bits/stdc++.h"
using namespace std;
int MaxPowerof2(int n)
{
    int x = 0;
    while ((x << 1) <= n)
        x++;
    return x;
}
int NumberOfSetbits(int n)
{
    if (n == 0)
        return 0;
    int x = MaxPowerof2(n);
    int bU2Rx = x * (1 << (x - 1)); // bU2Rx is equal to the number of setbits upto 2 raise to x-1;

    int msbFrom2RxToN = (n - (1 << x) + 1); // its equal to the number of msb setbits from 2^(x-1) to n;
    int rest = n - (1 << x);
    int ans = bU2Rx + msbFrom2RxToN + NumberOfSetbits(rest);
    return ans;
}
int main()
{
    int a = 17;
    cout << NumberOfSetbits(a);
    return 0;
}