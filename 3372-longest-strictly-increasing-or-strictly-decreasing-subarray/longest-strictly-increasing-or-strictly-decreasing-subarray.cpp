class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int l=0,r=1;
        int maxi=1;
        while(r<nums.size()){
            if(nums[r]>nums[r-1]){
                int len= r-l+1;
                maxi=max(maxi,len);
            }
            else l=r;
            r++;
        }
        l=0,r=1;
        while(r<nums.size()){
            if(nums[r]<nums[r-1]){
                int len= r-l+1;
                maxi=max(maxi,len);
            }
            else l=r;
            r++;
        }
        return maxi;
    }
};