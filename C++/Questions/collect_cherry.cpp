#include <bits/stdc++.h>
using namespace std;
// 741. Cherry Pickup   https://leetcode.com/problems/cherry-pickup/
class backTracking // This solution is based on backtracking and it gives TLE in leetcode
{                  // utility function to traverse the grid from top to bottom and modifies the max_collected_cherry ;
    void top2bottom(int cherry_collected, vector<vector<int>> &arr, int col, int row, int &max_collected_cherry)
    {
        if (row < 0 || col >= arr.size() || row >= arr.size() || col < 0 || arr[row][col] == -1)
            return;
        if (row == arr.size() - 1 && col == arr.size() - 1)
        {
            bottom2top(arr, col, row, cherry_collected, max_collected_cherry);
        }

        int cherry = arr[row][col];
        arr[row][col] = 0;
        top2bottom(cherry_collected + cherry, arr, col, row + 1, max_collected_cherry);
        top2bottom(cherry_collected + cherry, arr, col + 1, row, max_collected_cherry);
        arr[row][col] = cherry;
    }
    // utility function to traverse the grid from bottom to top and modifies the max_collected_cherry ;
    void bottom2top(vector<vector<int>> &arr, int col, int row, int cherry_collected, int &max_collected_cherry)
    {

        if (row < 0 || col >= arr.size() || row >= arr.size() || col < 0 || arr[row][col] == -1)
            return;
        if (row == 0 && col == 0)
        {
            max_collected_cherry = max(max_collected_cherry, cherry_collected);
            return;
        }
        int cherry = arr[row][col];
        arr[row][col] = 0;
        bottom2top(arr, col - 1, row, cherry_collected + cherry, max_collected_cherry);
        bottom2top(arr, col, row - 1, cherry_collected + cherry, max_collected_cherry);
        arr[row][col] = cherry;
    }
    int cherryPickup(vector<vector<int>> &grid) // main function
    {
        if (grid.size() == 1)
        {
            return grid[0][0] == -1 ? 0 : grid[0][0];
        }
        int max_cherry = 0, cherry = 0;
        top2bottom(cherry, grid, 0, 0, max_cherry);
        return max_cherry;
    }
};

//  in the above solution we go bottom-right and again comeback to the top-left::This is equivalent to two persons going from top-left to bottom-right;
class BackTracking2
{
    int dp[50][50][50];

public:
    int cherryPickup_utility(int r1, int c1, int r2, vector<vector<int>> &grid)
    {
        int c2 = r1 + c1 - r2;
        if (r1 >= grid.size() || r2 >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];
        // if p1 and p2 reaches destination then;
        if (r1 == grid.size() - 1 && c1 == grid[0].size() - 1 && r2 == grid.size() - 1 && c2 == grid[0].size() - 1)
            return grid[r1][c1];
        int cherries = 0;
        if (r1 == r2 && c1 == c2)
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];
        //here we have two persons p1 and p2 so we have four choices of movement HH,HV,VV & VH ;where H=horizontal and V=vertical; so we call function four times
        int cherry1 = cherryPickup_utility(r1, c1 + 1, r2, grid);     // both moving horizontal
        int cherry2 = cherryPickup_utility(r1 + 1, c1, r2, grid);     // p1 vertical p2 horizontal
        int cherry3 = cherryPickup_utility(r1 + 1, c1, r2 + 1, grid); // both moving vertical
        int cherry4 = cherryPickup_utility(r1, c1 + 1, r2 + 1, grid); // p1 horizontal p2 vertical

        cherries += max(max(cherry2, cherry1), max(cherry3, cherry4));
        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        int a = cherryPickup_utility(0, 0, 0, grid);
        return a <= 0 ? 0 : a;
    }
};
int main()
{
    vector<vector<int>> v = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    BackTracking2 s;
    cout << s.cherryPickup(v);
    return 0;
}