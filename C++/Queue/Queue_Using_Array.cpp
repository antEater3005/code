// QUEUE:Its a user defined data type which follows FIFO (First In First Out) property.
// there are two pointers front and back pointing at the start and end of the queue.
// Some basic functions in Queue:
// 1. enqueue(): its is same as push() in stack, it sends the data in the back of the queue.
// 2. dequeue(): same as pop() function in stack, remove data from the front of the queue.
// 3. peek(): same as top() function in stack, it points to the value at front of the queue.
// 4. empty(): same as empty() function in stack, it checks whether the queue is empty or not.

// IMPLEMENTATION OF QUEUE USING ARRAY:

#include <iostream>
using namespace std;
#define n 20
class queue
{

    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue(int x)
    {
        if (back == (n - 1))
        {
            cout << "No space.\n";
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {

            front++;
            arr[front] = x;
        }
    }
    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue is empty.\n";
            return;
        }
        else
        {
            front++;
        }
    }
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue is empty.\n";
            return -1;
        }

        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    queue a;
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(5);
    a.enqueue(6);
    a.enqueue(8);
    cout << a.peek() << endl;
    a.dequeue();
    cout << a.peek() << endl;
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    if (a.empty())
    {
        cout << "Empty\n";
    }
    else
    {
        cout << "Queue have some elements.\n";
    }
    cout << "OK, code is successfully executed.\n";
    a.peek();
    return 0;
}
