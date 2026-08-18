class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k==nums.size()) return *max_element(nums.begin(),nums.end());
       int i=0;
       int j=0;
       int maxi=-1;
       unordered_map<int,int>mpp;
       while(j<nums.size()){
        j=i;
        while(j<(i+k)){
            mpp[nums[j]]++;
            j++;
        }
        i++;
       }
       for(auto p:mpp){
        if(p.second==1) maxi=max(maxi, p.first);
       }
       return maxi;
    }
};