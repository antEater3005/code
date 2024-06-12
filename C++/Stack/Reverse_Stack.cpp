#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int a = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(a);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}
int main()
{
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(7);
    st.push(8);
    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "OK" << endl;
}
