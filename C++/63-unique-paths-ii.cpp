class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[0].size();j++){
                if(i==0 && j==0){
                    if(obstacleGrid[0][0]==1) return 0;
                    else obstacleGrid[0][0]=1;
                }
                else if(i==0){
                    if(obstacleGrid[0][j]==1 || obstacleGrid[0][j-1]==0) obstacleGrid[0][j]=0;
                    else obstacleGrid[0][j]=1;
                }
                else if(j==0){
                    if(obstacleGrid[i][0]==1 || obstacleGrid[i-1][0]==0) obstacleGrid[i][0]=0;
                    else obstacleGrid[i][0]=1;
                }
                else if(obstacleGrid[i][j]!=1){
                    obstacleGrid[i][j]=obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
                }
                else obstacleGrid[i][j]=0;
            }
        }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};