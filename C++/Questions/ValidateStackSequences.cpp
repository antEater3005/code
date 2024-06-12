// Its a google coding interview question.
#include "bits/stdc++.h"
using namespace std;
bool validStackSequences(queue<int> pushed, queue<int> popped)
{
    stack<int> ans;
    int n = popped.size();
    for (int i = 0; i < n; i++)
    {
        if (popped.front() != ans.top())
        {
            ans.push(pushed.front());
            pushed.pop();
        }
        if (popped.front() == ans.top())
        {
            ans.pop();
            popped.pop();
        }
    }

    if (popped.empty() && ans.empty())
    {
        return true;
    }
    else
        return false;
}
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    queue<int> q2;
    q2.push(4);
    q2.push(5);
    q2.push(3);
    q2.push(2);
    q2.push(1);
    if (validStackSequences(q1, q2))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    cout << "ok";
}
