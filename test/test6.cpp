#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int memo[s.size() + 1];
        memset(memo, 0, sizeof(memo));
        if (s.empty())
            return 0;
        memo[0] = 1;
        memo[1] = s[0] == '0' ? -1 : 1;
        for (int i = 2; i < s.size(); i++)
        {
            int a = stoi(s.substr(i - 1, 1)), b = stoi(s.substr(i - 2, 2));
            if (a != 0)
                memo[i] += memo[i - 1];
            if (b > 9 && b < 27)
                memo[i] += memo[i - 2];
        }
        return memo[s.size()];
    }
};
int main()
{
    vector<vector<int>> grid = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    return 0;
}
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        for (int i = 1; i < dungeon.size(); i++)
            dungeon[i][0] += dungeon[i - 1][0];
        for (int i = 1; i < dungeon[0].size(); i++)
            dungeon[0][i] += dungeon[0][i - 1];
        for (int i = 1; i < dungeon.size(); i++)
            for (int j = 1; j < dungeon[0].size(); j++)
            {
                dungeon[i][j] += min(dungeon[i - 1][j], dungeon[i][j - 1]);
            }
        return abs(dungeon[dungeon.size() - 1][dungeon[0].size() - 1]) + 1;
    }
};