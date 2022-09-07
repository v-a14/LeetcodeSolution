class Solution {
public:
    bool findPosition(vector<vector<char>>&board, int &x, int &y){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    x = i;
                    y = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool isPossible(vector<vector<char>>&board, int x, int y, int num){
        char temp = (char)(num + '0');
        // check in the current row 
        for(int i=0;i<9;i++){
            if(board[i][y] == temp) return false;
        }
        
        for(int i=0;i<9;i++){
            if(board[x][i] == temp) return false;
        }
        
        // check in the current box 
        int row = x/3 * 3;
        int col = y/3 * 3;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j] == temp) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>&board){
        int x,y;
        if(!findPosition(board, x, y)){
            return true;
        }
        // start putting every possible value from 1 to 9 ;
        for(int i=1;i<=9;i++){
            if(isPossible(board, x, y, i)){
                board[x][y] = (char)(i + '0');
                if(helper(board)) return true;
                board[x][y] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>&board){
        helper(board);
    }
};