// Name: Mahima Chauhan
// Date: 24/10/2022
// apply DFS for grid2, and if we can find 1 cell in grid1 is 0 and grid2 is 1 then this island is not a sub-island.
class Solution {
public:
    void check(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>&grid2,int &flag,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>= m || grid2[i][j]==0 )  // if index is out of bound or grid[i][j] is not 1
        return ;

    if(grid2[i][j]==1)   
    {
        if(grid1[i][j]==0)
        {   
            flag=0;
            return ; 
        }          
    }
    grid2[i][j]=0;  // Marking visited 
    
    // call for 4 directions
    check(i-1,j,grid1,grid2,flag,n,m); 
    check(i+1,j,grid1,grid2,flag,n,m);
    check(i,j-1,grid1,grid2,flag,n,m);
    check(i,j+1,grid1,grid2,flag,n,m);
    
    return ;
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
{
    int n=grid2.size(); // rows
    int m=grid2[0].size(); // columns
    int count=0; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid2[i][j]==1)
            {
                int flag=1;
                check(i,j,grid1,grid2,flag,n,m);
                if(flag==1)// If flag is 1 then increament the answer.
                count++;
            }   
        }
    }
    return count;
}
};