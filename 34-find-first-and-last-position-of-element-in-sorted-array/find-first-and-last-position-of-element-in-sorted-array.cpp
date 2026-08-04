class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*vector<int>ans;                             //this is the brute force here as the TC is O(n);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        if(ans.empty()) return {-1,-1};
        return { ans.front(),ans.back()}; */
         
        // the optimal solution for O(logn):
       int low=0;
       int high=nums.size()-1, first_occur=-1;
       while(low<=high){
        int mid= low+(high-low)/2;
        if(nums[mid]>=target){
            first_occur=mid;
            high=mid-1;
        }
        else low=mid+1;
       }
       if(first_occur==-1|| nums[first_occur]!=target) return {-1,-1};
       int last_occur=nums.size();
        low=0,high=nums.size()-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>target){
            last_occur=mid;
            high=mid-1;
        }
        else low=mid+1;
       }
       
       return {first_occur,last_occur-1};
    }
};