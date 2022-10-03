// Brute Force Approach : Recursion (Gives TLE)

class Solution {
public:
    int countPaths(int i,int j,int m,int n)
    {
        if(i>m || j>n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        return countPaths(i+1,j,m,n)+countPaths(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return countPaths(0,0,m,n);
    }
};
// Better Approach : Memoized Solution : Bottom Up DP (Accepted)

class Solution {
public:
    int countPaths(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>m || j>n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=countPaths(i+1,j,m,n,dp)+countPaths(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return countPaths(0,0,m,n,dp);
    }
};
// Optimal Solution : Combinatorics (Accepted)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=m-1;
        double ans=1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(N-r+i)/i;
        }
        return (int)ans;
    }
};
