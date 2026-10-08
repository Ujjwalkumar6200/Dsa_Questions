class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;
                char dig = board[row][col];
                
                for(int i = 0; i < 9; i++) {
                    
                    if(i != col && board[row][i] == dig) return false;
                    
                    if(i != row && board[i][col] == dig) return false;
    
                    int srow = 3*(row/3) + i/3;
                    int scol = 3*(col/3) + i%3;
                    if((srow != row || scol != col) && board[srow][scol] == dig) return false;
                }
            }
        }
        return true;
    }
};
