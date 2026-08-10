class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        /*int row=0;    // starting from [0][m-1] right top
        int col=m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]> target) col--;
            else row++;
        }
        return false;*/
         int row= n-1;
         int col= 0;
         while(row>=0 && col<m){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) row--;
            else col++;
         }
         return false;
        
        
    }
};