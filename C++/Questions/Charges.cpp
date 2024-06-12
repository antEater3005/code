// This question if from codechef having >>Problem Code:CHARGES.
#include "bits/stdc++.h"
using namespace std;
int dis(string a)
{
    int distance = 0, prev = a[0];
    for (int i = 1; i < a.length(); i++)
    {
        if (prev == a[i])
        {
            distance += 2;
            prev = a[i];
        }
        else
        {
            prev = a[1];
            distance++;
        }
    }
    return distance;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        string x = "";
        string y = "";
        for (int i = 0; i < N; i++)
        {
            int l;
            cin >> l;
            x += l;
        }
        for (int i = 0; i < K; i++)
        {
            int m;
            cin >> m;
            y += m;
        }
        for (int j = 0; j < K; j++)
        {
            int t = y[j] - 1;
            x[t] = abs(x[t] - 1);
            cout << dis(x) << " ";
        }
    }

    return 0;
}
