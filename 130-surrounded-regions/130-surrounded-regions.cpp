class Solution {
public:
    vector<int>dx = {1,0,-1,0};
    vector<int>dy = {0,1,0,-1};
    void dfsMark(vector<vector<char>>&board, int x, int y){
        board[x][y] = 'A';
        for(int i=0;i<4;i++){
            int currX = dx[i] + x;
            int currY = dy[i] + y;
            if(currX>=0 && currX<board.size() && currY>=0 && currY<board[0].size() && board[currX][currY] =='O'){
                dfsMark(board, currX, currY);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        //checking the first and last vertical column 
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O') dfsMark(board, i, 0);
            if(board[i][m-1] == 'O') dfsMark(board, i, m-1);
        }
        
        // checking the first and last horizontal row 
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O') dfsMark(board, 0, j);
            if(board[n-1][j] == 'O') dfsMark(board, n-1, j);
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
            for(int j=0;j<m;j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
        return;
        
        
    }
};