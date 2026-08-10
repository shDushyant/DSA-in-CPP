class Solution {
public:
    int max_element(vector<vector<int>>& mat,int n, int mid){
        int maxi= -1;
        int max_idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxi){
                maxi= mat[i][mid];
                max_idx=i;
            }
        }
        return max_idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       int low=0;
       int high= m-1;
       while(low<=high){
        int mid= low+(high-low)/2;
        int row_idx= max_element(mat,n,mid);
        int left= mid-1>=0? mat[row_idx][mid-1] : -1;
        int right= mid+1<m ? mat[row_idx][mid+1]: -1;
        if(mat[row_idx][mid]>left && mat[row_idx][mid]>right) return { row_idx,mid};
        else if( mat[row_idx][mid] <left) high=mid-1;
        else low=mid+1;
       }
       return {-1,-1};    
    }
};