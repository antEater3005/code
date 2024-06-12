#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }
    void push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
       
       swap(q1,q2);
    }
    void pop()
    {
        q1.pop();
        N--;
    }
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return N;
    }
    bool empty(){
        return N==0?true:false;
    }
};

int main()
{
    Stack st;
    st.push(2);
    st.push(5);
    st.push(6);
    st.push(9);
    while (!st.empty())
    {
    cout<<st.top()<<"->";
    st.pop();
    }
    
    return 0;
}