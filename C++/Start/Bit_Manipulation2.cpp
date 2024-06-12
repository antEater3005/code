#include <iostream>
using namespace std;
int setbit(int n, int pos)
//  The function setbit set the bit at pos to set i.e.,1;
{
    return (n | (1 << pos));
}
int main()
{
    int n, pos;
    cin >> n >> pos;
    cout << setbit(n, pos);
    return 0;
}