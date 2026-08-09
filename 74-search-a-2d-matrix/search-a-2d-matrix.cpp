class Solution {
public:
    /*int function(vector<int>&matrix, int m, int x){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(mid==x) return mid;
            else if(mid<x) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
            int check_value= function(matrix[i],m,target);  //check whether the target is prresent in that ranor     not 
            if(check_value==target) return true;
            }
            
        }
        return false; 
        }
        };
        */

        bool searchMatrix(vector<vector<int>>& matrix, int target){
        int n= matrix.size() ;// no. of rows
        int  m= matrix[0].size(); // no. of columns 
        int low= 0;
        int high= (n*m) -1;
        while(low<=high){
            int mid= low+(high-low)/2;
            int i= mid/m, j=mid%m;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
        
    }
};