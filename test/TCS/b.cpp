#include <bits/stdc++.h>
using namespace std;
static bool check(vector<string> &a, vector<string> &b)
{
    if (b.size() < a.size())
        return true;
    return false;
}
void subset1(vector<string> &str, int index, vector<vector<string>> &ans, vector<string> &temp)
{
    ans.push_back(temp);
    for (int i = index; i < str.size(); i++)
    {
        temp.push_back(str[i]);
        subset1(str, i + 1, ans, temp);
        temp.pop_back();
    }
    return;
}
// int countBits(int n, int res)
// {
//     vector<pair<int, int>> ans(n + 1, pair<int, int>());
//     ans[0] = {0, 0};
//     for (int i = 1; i <= n; i++)
//     {
//         ans[i] = {(ans[i / 2].second + i % 2), i};
//     }
//     sort(ans.begin(), ans.end(), check);
//     return ans[res - 1].second;
// }
// void subset(vector<string> &str, int n, int res)
// {
//     int a = 1, j = 0;
//     while (n--)
//         a *= 2;
//     a = a - 1;
//     int ans = countBits(a, res);
//     cout << ans;
//     vector<string> result;
//     while (ans)
//     {
//         if (ans & 1)
//             result.push_back(str[j]);
//         ans = ans >> 1;
//         j++;
//         cout << (ans & 1);
//     }
//     // reverse(begin(result), end(result));
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i];
//         if (i != result.size() - 1)
//             cout << ',';
//     }
// }
void ans(vector<string> &str, int n, int rank)
{
    vector<vector<string>> res;
    vector<string> temp;
    subset1(str, 0, res, temp);
    sort(begin(res), end(res), check);
    for (int i = 0; i < res[rank - 1].size(); i++)
    {
        cout << res[rank][i];
        if (i != res[rank - 1].size())
            cout << ",";
    }
}
int main()
{
    int n, rank;
    cin >> n >> rank;
    vector<string> str;
    string a;

    cin >> a;
    // cout << a;
    for (int i = 0; i < a.size(); i++)
    {
        string s = "";
        while (i < a.size() && a[i] != ',')
            s = s + a[i++];
        str.push_back(s);
    }
    ans(str, n, rank);
    return 0;
}
// 3
// 7
// abc,dab,bc
