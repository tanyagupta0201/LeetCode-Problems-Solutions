class Solution {
   public List<Integer> numOfIslands(int rows, int cols, int[][] operators) {
        //Your code here
        int[][] arr=new int[rows][cols];
        List<Integer> sol=new ArrayList<>();
        int ans=0;
        for(int i=0; i<operators.length; i++)
        {
            int row=operators[i][0];
            int col=operators[i][1];
            if(arr[row][col]!=1)
            {
                arr[row][col]=1;
                sol.add(countnumber(arr,rows,cols));
            }
            else
            {
                sol.add(sol.get(sol.size()-1));
            }
        }
        return sol;
    }

    public static int countnumber(int[][] arr,int row,int col){
        int count=0;
        int[][] temp=new int[row][col];
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                temp[i][j]=arr[i][j];
            }
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(temp[i][j]==1)
                {
                    count++;
                    dfs(temp,i,j,row,col);
                }
            }
        }
        return count;
    }
    public static void dfs(int[][] arr,int i,int j,int row,int col)
    {
        if(i<0 || j<0 || i>row-1 || j>col-1 || arr[i][j]!=1)return;
        if(arr[i][j]==1)
        {
            arr[i][j]=0;
            dfs(arr,i+1,j,row,col);
            dfs(arr,i-1,j,row,col);
            dfs(arr,i,j+1,row,col);
            dfs(arr,i,j-1,row,col);
        }
    }
}
