#include <iostream>
using namespace std;
int main()
{
    float a, b;
    cout << "Enter two numbers:";
    cin >> a >> b;
    cout << "Operator:";
    char op;
    cin >> op;
    switch (op)
    {
    case '+':
        cout << "sum=" << a + b;
        break;
    case '-':
        cout << "Difference=" << a - b;
        break;
    case '*':
        cout << "Product=" << a * b;
        break;
    case '/':
        cout << "Quotient=" << a / b;
        break;
    default:
        cout << "Math Error=";
    }
    return 0;
}