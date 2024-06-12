#include <iostream>
using namespace std;
void passByValue(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
void passByReference(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}
int main()
{
    int a = 4, b = 7;
    cout << "before " << a << " " << b << endl;
    passByReference(a, b);
    cout << "after  " << a << " " << b << endl;

    return 0;
}