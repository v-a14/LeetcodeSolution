class Solution {
public:
    bool isPossible(vector<string>&board, int x, int y){
        // chek the current column 
        // check the upper diagonals(left, and right)
        
        // checking the column 
        for(int i=0;i<x;i++){
            if(board[i][y] == 'Q') return false;
        }
        
        // checking the upper left diagonal 
        int j = y-1;
        for(int i=x-1;i>=0 && j>=0;i--){
            if(board[i][j] == 'Q') return false;
            j--;
        }
        
        // checking the upper right diagonal 
        j = y+1;
        int m = board[0].size();
        for(int i=x-1;i>=0 && j<m;i--){
            if(board[i][j] == 'Q') return false;
            j++;
        }
        
        return true;
        
    }
    void queenHelper(int n, int row, vector<string>&board, vector<vector<string>>&ans){
        // if we hit the last row, means we have placed all the queens on the board 
        if(n == row){
            ans.push_back(board);
            return;
        }
        
        
        // trying to place the current queen 
        for(int j=0;j<n;j++){
            if(isPossible(board, row, j)){
                board[row][j] = 'Q';
                queenHelper(n, row+1, board, ans);
                board[row][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }
        queenHelper(n, 0, board, ans);
        return ans;
        
        
    }
};