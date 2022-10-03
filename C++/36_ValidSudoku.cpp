// Name : Ashish Prasad Thakur
// Date : 3/10/2022

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y){
        char test = board[x][y];
        
        // column check
        for(int i=0; i<9; i++){
            if(i!=x && board[i][y]==test)
                return false;
        }
        // row check
        for(int i=0; i<9; i++){
            if(i!=y && board[x][i]==test)
                return false;
        }
        // box check
        int xstart = (x/3) * 3;
        int ystart = (y/3) * 3;
        int cnt = 0;
        for(int i=xstart; i<xstart+3; i++){
            for(int j=ystart; j<ystart+3; j++){
                if(board[i][j] == test)
                    cnt++;
            }
        }
        if(cnt>1)
            return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.' && isValid(board, i, j) == false){
                    return false;
                }
            }
        }
        return true;
    }
};