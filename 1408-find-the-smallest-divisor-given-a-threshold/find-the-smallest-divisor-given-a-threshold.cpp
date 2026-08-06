class Solution {
public:
    int function(vector<int>&nums,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= ceil((double)nums[i]/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high= *max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int result= function(nums,mid);
            if(result<=threshold){
             ans= min(mid,ans);
             high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};