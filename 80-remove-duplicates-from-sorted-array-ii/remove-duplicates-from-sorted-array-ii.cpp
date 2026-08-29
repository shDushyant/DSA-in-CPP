class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>2) continue;
            ans.push_back(nums[i]);
        }
         for (int i = 0; i < ans.size(); i++) {
            nums[i] = ans[i];
         }
        return ans.size();
    }
};