class Solution {
public:
    void findcombination(int idx,int k,int sum,vector<int>&ds,vector<vector<int>>&ans){
        if(k==0 && sum==0){
            ans.push_back(ds);
            return;
        }
        else if(k==0 || sum==0) return ;
        for(int i=idx;i<=9;i++){
            ds.push_back(i);
            findcombination(i+1,k-1,sum-i,ds,ans);
            ds.pop_back();
            //findcombination(i+1,k,sum,ds,ans);
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        if(n<k) return {};
        findcombination(1,k,n,ds,ans);
        return ans;
        
    }
};