class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>lonely;
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
        }
        for(int i=0;i<n;i++){
            if(mpp[nums[i]]==1){
                if(mpp[nums[i]+1]==0 && mpp[nums[i]-1]==0) lonely.push_back(nums[i]);
            }
        }
        
        
        return lonely;
        
    }
};