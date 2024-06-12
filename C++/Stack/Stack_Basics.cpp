//Stack: it stores list of items in which an item can be only added or removed from the list only at the one end.
// It  works on last in first out(LIFO) mechanism.
// its like stack of coins
#include <iostream>
using namespace std;
int n = 100;
class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow.\n";
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop.\n";
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    stack sa;
    sa.push(3);
    sa.push(5);
    sa.push(8);
    sa.push(9);
    cout << sa.Top() << endl;
    sa.pop();
    cout << sa.Top() << endl;
    sa.pop();
    sa.pop();
    sa.pop();
    sa.pop();
    sa.Top();
    cout<<sa.empty()<<endl;
    cout << "OK";
    return 0;
}