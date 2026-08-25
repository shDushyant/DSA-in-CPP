class Solution {
public:
    int funct(vector<int>&nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return target;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());    //nlogn
        //vector<int>ans_store;
       /* int maxi=0;
        for(int i=0;i<nums.size();i++){     //o(n)
            if(nums[i]%k==0)  maxi=max(maxi,nums[i]);
        }*/
        int maxi=*max_element(nums.begin(),nums.end());
        int last = maxi/k;
        for(int i=1;i<=last+1;i++){
            int ans= funct(nums,k*i);
            if(ans!=(k*i)) return k*i;
        }
return -1;
    }
};