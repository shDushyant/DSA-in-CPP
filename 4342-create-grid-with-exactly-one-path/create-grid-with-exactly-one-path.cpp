class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m,string(n,'#'));
        ans[0][0]='.';
        ans[m-1][n-1]='.';
        int i=0;int j=0;
        while(i<m && j<n){
            if(i==m-1 && j==n-1) break;
            if(j+1<n){
                ans[i][j+1]='.';
                j++;
            }
            else if(i+1<m){
                ans[i+1][j]='.';
                i++;
            }
        }
        return ans;
        }
};