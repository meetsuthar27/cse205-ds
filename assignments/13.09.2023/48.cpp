#include <bits/stdc++.h>

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int temp;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix[0].size(); j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (int j = 0; j < matrix[0].size(); j++)
        {
            reverse(matrix[j].begin(), matrix[j].end());
        }
    }
};