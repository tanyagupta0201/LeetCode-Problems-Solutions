class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // treat the matrix as an array, just taking care of indices
        // [0..n*m]
        // (row, col) -> row*n + col
        // i -> [i/n][i%n]
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=n-1;
        while(i<m && j>=0)
        {
            if(target==matrix[i][j])
            {
                return true;
            }
            else if(target<matrix[i][j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};
