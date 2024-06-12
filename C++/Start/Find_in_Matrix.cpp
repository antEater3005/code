// Its an algorithm of finding a number present in a sorted matrix(2 - d Array) in both row and column wise;
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int target;

    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    cin >> target;
    int r = 0, c = m - 1;
    bool found = false;
    while (r < n and c >= 0)
    {
        if (mat[r][c] == target)
        {
            found = true;
        }
        if (mat[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (found)
    {
        cout << "Element is found.";
    }
    else
    {
        cout << "Elemnt does not exist.";
    }

    return 0;
}