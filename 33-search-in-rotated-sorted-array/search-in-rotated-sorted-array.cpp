class Solution {
    public:
        int search(vector<int>& nums, int target) {

        /*int n=nums.size();        brute force 
        int k;                   
        int flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                k= i;
                flag=1;
                break;
            }
        }
        if(flag==1) return k;
        else return -1;*/

        // optimal :  BS
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target ) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                } 
                else low=mid+1;
            }
            else{
                if(nums[mid]<=target && target <=nums[high]){
                   low= mid+1;
                }
                else high=mid-1;
            }
        }
            

       return -1; 
    }
};