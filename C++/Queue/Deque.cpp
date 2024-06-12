// Deque: it means doubly ended queue.
// we can insert and delete from both end.
// header file <deque>.
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> dq;
    dq.push_back(3);
    dq.push_front(6);
    dq.push_back(7);
    dq.push_front(2);
    for (auto i : dq)
    {
        cout << i << " ";
    }
    dq.pop_back();
    dq.pop_front();

    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout<<dq.size();
    cout << "\nOK\n";
    return 0;
}