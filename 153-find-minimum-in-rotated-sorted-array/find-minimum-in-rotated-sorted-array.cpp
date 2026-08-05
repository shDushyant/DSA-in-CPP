class Solution {
public:     
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int mind=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            mind=min(mind,nums[mid]);
            if(nums[low]<=nums[mid]){
                mind=min(mind,nums[low]);
                low=mid+1;
            }
            else{
                mind=min(mind,nums[mid]);
                high=mid-1;
            }
        }
        return mind;
    }
};