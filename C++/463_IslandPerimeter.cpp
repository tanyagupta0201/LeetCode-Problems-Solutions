//Name:Mahima Chauhan
//Date:14/10/2022
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();//row of grid
        int n=grid[0].size();//column of grid
        int cnt=0;// store perimeter 
//to calculate the perimeter we need to check the value of 4 sides of the land that is if it is water or not
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                if(i==0 || grid[i-1][j]==0) cnt++;
                if(j==0 || grid[i][j-1]==0) cnt++;
                if(i==m-1 || grid[i+1][j]==0) cnt++;
                if(j==n-1 || grid[i][j+1]==0) cnt++;
                }
                    
                
            }
        }
        return cnt;
        
    }
};