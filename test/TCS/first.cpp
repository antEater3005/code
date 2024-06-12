#include <bits/stdc++.h>
using namespace std;
int result(vector<int> &arrive, int n, int interval, int capacity)
{
    int count = 0;
    queue<int> q;
    int j = 0, protocol = -1;
    for (int i = 0; i <= interval; i++)
    {

        if (protocol == i)
            protocol = -1;

        if (!q.empty() && q.front() == i)
        {
            cout << q.front() << " ";
            q.pop();

            count++;
        }

        if (i <= arrive[j] && q.size() < capacity)
            protocol = -1;

        if (j < n && q.size() < capacity && arrive[j] <= i && protocol == -1)
        {

            q.push(i + 30);
            j++;
        }
        if (protocol == -1 && q.size() == capacity)
            protocol = i + 15;
    }
    return count;
}
int main()
{
    int capacity, n;
    cin >> capacity;
    string starttime, endTime;
    cin >> starttime >> endTime;
    cin >> n;
    vector<int> arrive;
    for (int i = 0; i < n; i++)
    {
        int arr;
        cin >> arr;
        arrive.push_back(arr);
    }
    int h = ((endTime[0] - '0') * 10 + (endTime[1] - '0')) - ((starttime[0] - '0') * 10 + (starttime[1] - '0'));
    int m = ((endTime[3] - '0') * 10 + (endTime[4] - '0')) - ((starttime[3] - '0') * 10 + (starttime[4] - '0'));
    int interval = h * 60 + m;
    for (int a : arrive)
        cout << a << " ";
    cout << result(arrive, n, interval, capacity);
    return 0;
}