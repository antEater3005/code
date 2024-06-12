#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
class Solution
{
    int neighbors(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        int tl, t, tr, r, br, b, bl, l;
        tl = i > 0 && j > 0 && (grid[i - 1][j - 1] == 1 || grid[i - 1][j - 1] == 3) ? 1 : 0;
        t = i > 0 && (grid[i - 1][j] == 1 || grid[i - 1][j] == 3) ? 1 : 0;
        tr = i > 0 && j < n - 1 && (grid[i - 1][j + 1] == 1 || grid[i - 1][j + 1] == 3) ? 1 : 0;
        r = j < n - 1 && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3) ? 1 : 0;
        br = i < m - 1 && j < n - 1 && (grid[i + 1][j + 1] == 1 || grid[i + 1][j + 1] == 3) ? 1 : 0;
        b = i < m - 1 && (grid[i + 1][j] == 1 || grid[i + 1][j] == 3) ? 1 : 0;
        bl = i < m - 1 && j > 0 && (grid[i + 1][j - 1] == 1 || grid[i + 1][j - 1] == 3) ? 1 : 0;
        l = j > 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 3) ? 1 : 0;
        return tl + t + tr + r + br + b + bl + l;
    }

public:
    void gameOfLife(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int neighbor = neighbors(grid, i, j, m, n);
                if (neighbor == 3 && grid[i][j] == 0)
                    grid[i][j] = 5;
                else if (grid[i][j] == 1 && (neighbor < 2 || neighbor > 3))
                    grid[i][j] = 3;
            }
        }
        for (auto &a : grid)
            for (int &it : a)
                if (it == 3)
                    it = 0;
                else if (it == 5)
                    it = 1;
    }
};