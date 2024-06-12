#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node(int val)
    {
        data = val;
        link = NULL;
    }
};
class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void enqueue(int val)
    {
        node *n = new node(val);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->link = n;
        back = n;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }
        node *todelete = front;
        front = front->link;
        free(todelete);
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "No element in queue.\n";
            return -1;
        }
        cout << front->data << endl;
    }
    bool empty()
    {

        if (front == NULL)
        {

            return true;
        }
        return false;
    }
};
int main()
{
    queue a;
    a.enqueue(7);
    a.enqueue(4);
    a.enqueue(6);
    a.enqueue(2);
    a.enqueue(9);
    cout << a.peek();
    a.dequeue();
    cout << a.peek();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    if (a.empty())
    {
        cout << "queue is empty.\n";
    }
    else
    {
        cout << "Queue have some elements.\n";
    }
    cout << a.peek();
    return 0;
}