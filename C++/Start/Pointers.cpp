//Pointer are variable which store address of other variable.
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *aptr;
    aptr = &a;
    cout << &a << endl;
    cout << a << endl;
    *aptr = 20;
    cout << *aptr << endl;
    cout << sizeof(a);
    return 0;
}