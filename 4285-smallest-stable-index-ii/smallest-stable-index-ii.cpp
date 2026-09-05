class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        /*int maxi=nums[0];                 it was brute force 
        for(int i=0;i<nums.size();i++){
           if(nums[i]>=maxi) maxi=nums[i];
           int mini=INT_MAX;
           for(int j=i;j<nums.size();j++){
            if(nums[j]<mini) mini=nums[j];
           }
           if((maxi-mini)<=k) return i;
        }
        return -1;*/

        //optimal approach:
        vector<int>mini(nums.size());
        mini[mini.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<mini[i+1]) mini[i]=nums[i];
            else mini[i]=mini[i+1];
        }
        int i=0;
        int j=0;
        int maxi=-1;
        while(i<nums.size() && j<mini.size()){
           if(nums[i]>maxi) maxi=nums[i];
           if((maxi-mini[j])<=k) return i;
           i++;
           j++;
        }
        return -1;
    }
};