class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini=INT_MAX;
        for(int k=l;k<=r;k++){
        int i=0;
        int j=i;
        int sum=0;
        while(j<nums.size()){
           sum+=nums[j];
           while((j-i+1)>k){
            sum-=nums[i];
            i++;
           }
            if((j-i+1) == k && sum > 0) {
                    mini = min(mini, sum);
                }
           j++;
        }
        }
         return mini == INT_MAX ? -1 : mini;
    }
};