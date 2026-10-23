class Solution {
public:
    void permute(vector<int>&nums,vector<int>&ds, vector<vector<int>>&ans,int freq[], set<vector<int>>&st){
        if(ds.size()==nums.size()){
            if(!st.count(ds)) ans.push_back(ds);
            st.insert(ds); 
            return;
    }
    for(int i=0;i<nums.size();i++){
       if(freq[i]==0){
        ds.push_back(nums[i]);
        freq[i]=1;
        permute(nums,ds,ans,freq,st);
        ds.pop_back();
        freq[i]=0;
       }
    }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        set<vector<int>>st;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        permute(nums,ds,ans,freq,st);
        return ans;
        
    }
    
};