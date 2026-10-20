class Solution {
public:
    bool checkvalid(vector<vector<char>>&board,int row,int col, char c){
        for(int i=0;i<9;i++){
             // Check column, excluding current cell
            if (i != row && board[i][col] == c)
                return false;

            // Check row, excluding current cell
            if (i != col && board[row][i] == c)
                return false;

            // Check 3x3 sub-box
            int r = 3 * (row / 3) + i / 3;
            int cl = 3 * (col / 3) + i % 3;

            if ((r != row || cl != col) && board[r][cl] == c)
                return false;
        }
        return true;
        }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    char c= board[i][j];
                    if(checkvalid(board,i,j,c)==false) return false;
                }
            }
        }
        return true;
    }
};