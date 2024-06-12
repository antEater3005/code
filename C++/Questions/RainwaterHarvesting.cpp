#include "bits/stdc++.h"
using namespace std;
int rainWater(vector<int> a)
{
    stack<int> st;
    int n = a.size();
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int difference = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur]) * difference;
        }
        st.push(i);
    }
    return ans;
}

int rainWaterTraping(vector<int >arr )
{
    int n = arr.size();
    int left[n], right[n], water = 0;
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - arr[i];
    }
    return water;
}
int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n=a.size();
    cout << rainWater(a)<<endl;
    cout<<rainWaterTraping(a);
    return 0;
}