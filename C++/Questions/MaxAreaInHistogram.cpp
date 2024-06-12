#include "bits/stdc++.h"
using namespace std;
int largestRectangleArea(vector<int> &h)
{
    stack<int> st;
    int i = 0, n = h.size(), ans = 0;
    while (i < n)
    {
        while (!st.empty() && h[st.top()] > h[i])
        {
            int ht = h[st.top()];
            st.pop();
            if (st.empty())
                ans = max(ans, ht * i);
            else
            {
                int width = i - st.top() - 1;
                ans = max(ans, ht * width);
            }
        }
        st.push(i++);
    }
    while (!st.empty())
    {
        int ht = h[st.top()];
        st.pop();
        if (st.empty())
            ans = max(ans, ht * i);
        else
        {
            int width = i - st.top() - 1;
            ans = max(ans, width * ht);
        }
    }

    return ans;
}
int largestRectangleArea_2(vector<int> &heights)
{
    int ans = 0, n = heights.size();
    int l_smaller[n];
    l_smaller[0] = -1;
    int r_smaller[n];
    r_smaller[n - 1] = n;

    for (int i = 1; i < n; i++)
    {
        int p = i - 1;
        while (p >= 0 && heights[p] >= heights[i])
            p = l_smaller[p];
        l_smaller[i] = p;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        int p = i + 1;
        while (p < n && heights[p] >= heights[i])
            p = r_smaller[p];
        r_smaller[i] = p;
    }
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (r_smaller[i] - l_smaller[i] - 1));
    }

    return ans;
}
int main()
{
    vector<int> a = {2, 4};
    cout << largestRectangleArea(a);
    return 0;
}