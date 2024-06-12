#include <iostream>
using namespace std;
//IN DECREASING ORDER.
void dec(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    dec(n - 1);
}
// FOR INCREASING ORDER.
void inc(int n)
{

    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    inc(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;
    inc(n);
    cout << " ";
    return 0;
}