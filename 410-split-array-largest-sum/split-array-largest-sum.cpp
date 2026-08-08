class Solution {
public:
    int sum_total(vector<int>&nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum;
    }
    int function(vector<int>&nums,int capacity_per_painter){
        int painter=1; int paint_units=0;
        for(int i=0;i<nums.size();i++){
            if(paint_units + nums[i]> capacity_per_painter){
                 painter++;
                 paint_units=nums[i];
            }
            else{
                paint_units +=nums[i];
            }
        }
        return painter;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=sum_total(nums);
        while(low<=high){
            int mid=low+(high-low)/2;
            int no_painter= function(nums,mid);
            if(no_painter>k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
        
    }
};