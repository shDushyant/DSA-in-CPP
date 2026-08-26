class Solution {
public:
    int subarraySum(vector<int>&nums,int goal){
        int l=0,r=0,sum=0,cnt=0;
        while(r<nums.size()){
            sum+=(nums[r]%2);
            while(sum>goal){
            sum-=(nums[l]%2);
            l++;
            }
            cnt+= (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(k<0) return 0;
         int cnt1= subarraySum(nums,k);
         int cnt2= subarraySum(nums,k-1);
         return cnt1-cnt2;
    }
};