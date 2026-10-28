/*class Solution {
public:
    void funct(int i,int j,vector<vector<int>>&grid,int* mini_xor,int xor1){
        xor1^=grid[i][j];
        if(i==grid.size()-1 && j==grid[0].size()-1){
            *mini_xor= min(*mini_xor,xor1);
            return;
        }
        if(i+1<grid.size()){
            funct(i+1,j,grid,mini_xor,xor1);
        }
        if(j+1<grid[0].size()){
            funct(i,j+1,grid,mini_xor,xor1);
        }
    }
    int minCost(vector<vector<int>>& grid) {
        int mini_xor=INT_MAX;
        int xor1=0;
        funct(0,0,grid,&mini_xor,xor1);
        return mini_xor;
    }
};*/  // using recursion , it is brute force for this que;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) return x;
        }

        return -1;
    }
};