#include "bits/stdc++.h"
using namespace std;
// The following function checks the present validity of the sudoku.
bool IsSudokuValid(vector<vector<int>> mat, int col, int row)
{
    int n = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        vector<int> colm(9, 0);
        vector<int> row(9, 0);
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0) // This part checks the duplicates in the column.
            {
                if (colm[mat[i][j] - 1] == 0)
                    colm[mat[i][j] - 1] += 1;
                else
                    return false;
            }
            if (mat[j][i] != 0) // This part checks the duplicates in the row.
            {
                if (row[mat[j][i] - 1] == 0)
                    row[mat[j][i] - 1] += 1;
                else
                    return false;
            }
            if (i % 3 == 0 && j % 3 == 0) //This part checks duplicates in a 3x3 matrix.
            {
                vector<int> box(9, 0);
                for (int k = i; k < (i + 3); k++)
                {
                    for (int l = j; l < (j + 3); l++)
                    {
                        if (mat[k][l] != 0)
                        {
                            if (box[mat[k][l] - 1] == 0)
                                box[mat[k][l] - 1] += 1;
                            else
                                return false;
                        }
                    }
                }
            }
        }
    }

    return true; // if there are no duplicates in columns,rows and in3x3 boxes, it return true.
}
int main()
{
    vector<vector<int>> ans = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 9, 0}, {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0}, {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0}, {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4}, {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (IsSudokuValid(ans, 9, 9))
        cout << "Valid";
    else
        cout << "Invalid";
    // cout << ans[0].size();
    // vector<int> a(9, 0);

    return 0;
}