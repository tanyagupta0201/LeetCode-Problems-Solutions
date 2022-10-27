class Solution {
public:

    bool issafe(int xi,int xj,char i,vector<vector<char>>& board)
    {
        //row
        for(int col=0;col<9;col++)
        {
            if(board[xi][col]==i)
                return 0;
        }
        //column
        for(int row=0;row<9;row++)
        {
            if(board[row][xj]==i)
                return 0;
        }
        //box
        int sr=xi-(xi%3);
        int sc=xj-(xj%3);
        for(int p=0;p<3;p++)
        {
            for(int q=0;q<3;q++)
                if(board[sr+p][sc+q]==i)return 0;
        }
        return 1;
    }
    bool sol(vector<vector<char>>& board){
     for(int x=0;x<9;x++)
     {for(int y=0;y<9;y++){
         if(board[x][y]=='.'){
        for(char i='1';i<='9';i++)
        {
            if(issafe(x,y,i,board))
            {
                board[x][y]=i;
                if(sol(board)) return true;
                else board[x][y]='.';
            }
        }
          return false;
        }
     }
        } return true;;
    }
    void solveSudoku(vector<vector<char>>& board) {
       if( sol(board)) return;
    }
};