class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>target_idx;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) target_idx.push_back(i);
        }
        if(target_idx.empty()) return {};
        return target_idx;
    }
};