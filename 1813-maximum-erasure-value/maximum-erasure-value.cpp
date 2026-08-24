class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int l=0,r=0;
        long long sum=0;
        long long summax=0;
        while(r<nums.size()){
         mpp[nums[r]]++;
         sum+=nums[r];
         while(mpp[nums[r]]>1){
            mpp[nums[l]]--;
            sum-=nums[l];
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
         }
         summax=max(summax,sum);
         r++;
        }
        return summax;
    }
};