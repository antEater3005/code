// QUEUE USING STACK:

#include <iostream>
#include <stack>
using namespace std;
class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int val) // time complexity = O(1).as
    {
        s1.push(val);
    }
    int dequeue() // time complexity of dequeue() function is of 'O(N)' order of N=number of elements in queue.
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty.";
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
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