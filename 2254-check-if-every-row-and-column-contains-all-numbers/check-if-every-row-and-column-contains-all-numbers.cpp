class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        vector<int>freq(n,0);
        for(int i=0;i<n;i++){
            freq[i]=i+1;
        }
        for(int i=0;i<matrix.size();i++){
            vector<int>hash(n,0);
            for(int j=0;j<n;j++){
              hash[j]=matrix[i][j];
            }
            sort(hash.begin(),hash.end());
            for(int k=0;k<n;k++){
                if(freq[k]!=hash[k]) return false;
            }
        }
        for (int j = 0; j < n; j++) {
            vector<int> hash(n);

            for (int i = 0; i < n; i++) {
                hash[i] = matrix[i][j];
            }

            sort(hash.begin(), hash.end());

            for (int k = 0; k < n; k++) {
                if (freq[k] != hash[k]) {
                    return false;
                }
            }
        }
        return true; 
    }
};