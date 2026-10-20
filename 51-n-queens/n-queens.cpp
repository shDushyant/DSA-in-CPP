class Solution {
public:
    bool issafe(int n,int row,int col, vector<string>&board){
        //checking diagonal up
        int duprow=row;           //storing row and col in duplicate row and col so that it can be used again;
        int dupcol=col;
        while(duprow>=0 && dupcol>=0){
            if(board[duprow][dupcol]=='Q') return false;
            duprow--;
            dupcol--;
        }
        //checking straight left
        duprow=row,dupcol=col;
        while(dupcol>=0){
            if(board[duprow][dupcol]=='Q') return false;
            dupcol--;
        }
        //checking diagonal down
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int n,int col, vector<string>&board, vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(n,row,col,board)==true){
                board[row][col]='Q';
                solve(n,col+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(n,0,board,ans);
        return ans;  
    }
};