class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n= nums.size();
        long long temp=nums[n-1];
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i]>temp) temp=nums[i];
            else{
                temp+=nums[i];
            }
        }
        return temp;
    }
};