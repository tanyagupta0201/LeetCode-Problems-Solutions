// Name: Laasya Gupta
// Date: 02/10/2022

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for (int row = 0; row < n; row++)
        {
            int Start_Col = 0, End_Col = n - 1;
            while (Start_Col < End_Col)
            {
                swap(matrix[row][Start_Col], matrix[row][End_Col]);
                Start_Col++;
                End_Col--;
            }
        }
    }
};