// USING FUNCTION CALL STACK.
// QUEUE USING STACK:

#include <iostream>
#include <stack>
using namespace std;
class queue
{
    stack<int> s1;

public:
    void enqueue(int val) // time complexity = O(1).as
    {
        s1.push(val);
    }
    int dequeue() // time complexity of dequeue() function is of 'O(N)' order of N=number of elements in queue.
    {
        if (s1.empty())
        {
            cout << "Queue is empty.";
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        int item = dequeue();
        s1.push(x);
        return item;
    }
    bool empty()
    {
        if (s1.empty())
        {
            cout << "Queue is empty.";
            return true;
        }
        return false;
    }
};

int main()
{
    queue a;
    a.enqueue(2);
    a.enqueue(4);
    a.enqueue(6);
    a.enqueue(5);
    cout << a.dequeue() << endl;
    cout << a.dequeue() << endl;
    cout << a.dequeue() << endl;
    cout << a.dequeue() << endl;
    a.empty();
    cout << a.dequeue() << endl;
    a.empty();
    return 0;
}