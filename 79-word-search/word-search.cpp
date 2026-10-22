class Solution {
public:
    int  checkWord(int i,int j, int k, string &ds,vector<vector<char>>&board, string &word){
      int m= board.size(), n=board[0].size();
      if(ds==word) return 1;
      char temp=board[i][j];
      board[i][j]='1';
      if(k<word.size()){
      if(i+1<m && board[i+1][j]==word[k]){
        ds+=board[i+1][j];
        if(checkWord(i+1,j,k+1,ds,board,word)){  // since it is a int function its manadatory to return a value;
            board[i][j] = temp;
                    return 1;
        }
        ds.pop_back();
      }
      if(i-1>=0 && board[i-1][j]==word[k]){
        ds+=board[i-1][j];
        if(checkWord(i-1,j,k+1,ds,board,word)){
            board[i][j] = temp;
                    return 1;
        }
        ds.pop_back();
      }
      if(j+1<n && board[i][j+1]==word[k]){
        ds+=board[i][j+1];
        if(checkWord(i,j+1,k+1,ds,board,word)){
            board[i][j] = temp;
                    return 1;
        }
        ds.pop_back();
      }
      if(j-1>=0 && board[i][j-1]==word[k]){
        ds+=board[i][j-1];
        if(checkWord(i,j-1,k+1,ds,board,word)){
            board[i][j] = temp;
                    return 1;
        }
        ds.pop_back();
      }
    }
    board[i][j]=temp;
    return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                string ds="";
                if(board[i][j]==word[0]){
                    ds+=board[i][j];               // passing k=1 since first word matches
                    if(checkWord(i,j,1,ds,board,word))return true;
                }
            }
        }
        return false;
    }
};