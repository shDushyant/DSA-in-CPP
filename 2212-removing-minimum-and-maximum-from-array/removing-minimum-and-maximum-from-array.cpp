class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<=2) return nums.size();
        int maxi=INT_MIN, mx=-1;
        int mini=INT_MAX,mnx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                mx=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                mnx=i;
            }
        }
         int left = min(mnx, mx);
        int right = max(mnx, mx);

        // 1. Both from left
        int option1 = right + 1;

        // 2. Both from right
        int option2 = n - left;

        // 3. One from left, one from right
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};