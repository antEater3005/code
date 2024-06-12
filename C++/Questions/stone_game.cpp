#include <bits/stdc++.h>
using namespace std;
// // stone game 1
// int kar98(vector<int> piles, int s, int e, int a, vector<vector<int>> &memo)
// {
//     if (s > e)
//         return 0;
//     if (memo[s][e] != -1)
//         return memo[s][e];

//     int left = a + piles[s] + kar98(piles, s + 2, e, a, memo);
//     int right = a + piles[s] + kar98(piles, s + 1, e - 1, a, memo);
//     int left2 = a + piles[e] + kar98(piles, s, e - 2, a, memo);
//     int right2 = a + piles[e] + kar98(piles, s + 1, e - 1, a, memo);
//     return memo[s][e] = max(a, max(left, max(right, max(left2, right2))));
// }
// bool stoneGame(vector<int> &piles)
// {

//     int alice = 0, bob = 0, end = piles.size() - 1, start = 0;

//     vector<vector<int>> memo(end, vector<int>(piles.size(), -1));
//     alice = kar98(piles, start, end, alice, memo);
//     bob = accumulate(piles.begin(), piles.end(), 0) - alice;
     
//     return alice > bob - alice ? true : false;
// }
// stone Game 2
int fucU(vector<int> piles, int s, int e, vector<vector<int>> &dp)
{

    if (s > e)
        return 0;
    if (dp[s][e] != 0)  
        return dp[s][e];
    bool even = (e - s) % 2;
    int left = even ? piles[s] : 0;
    int right = even ? piles[e] : 0;
    return dp[s][e] = max(fucU(piles, s + 1, e, dp) + left, fucU(piles, s, e - 1, dp) + right);
}
int stoneGameII(vector<int> &piles)
{
    int end = piles.size() - 1;
    vector<vector<int>> memo(piles.size() + 2, vector<int>(piles.size() + 2, -1));
    fucU(piles, 0, end, memo);
    for (auto a : memo)
    {
        for (auto b : a)
            cout << b << " ";
        cout << "\n";
    } e
}

int main()
{
    
vector<int> a = {5, 35, 59, 66, 69, 53, 37, 16, 60, 98, 11, 33, 3, 85, 59, 65, 59, 44, 34, 89, 72, 47};
    sort(a.begin(), a.end());
    for (int s : a)
        cout << s << " ";
    return 0;
}