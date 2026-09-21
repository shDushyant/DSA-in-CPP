class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int y= target-nums[i];
            if(mpp.find(y)!=mpp.end()){
                if(mpp[y]!=i)
                return {i,mpp[y]};
            }
        }
        return {};
    }
};