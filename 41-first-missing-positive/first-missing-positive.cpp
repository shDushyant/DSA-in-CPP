class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*sort(nums.begin(),nums.end());
        int mini=nums[0];
        int maxi=nums[nums.size()-1];
        if(mini>1 || maxi<=0) return 1;
        for(int i=0;i<nums.size();i++){
             if(nums[i]!=nums[i]+1) return nums[i]+1;
        }
        return maxi+1;*/
        int n=nums.size();
        vector<int>hash(n+1,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<=n){
                hash[nums[i]]++;
            }
        }
        for(int i=1;i<hash.size();i++){
            if(hash[i]==0) {
                return i;
        }
        }
        return n+1;
    }
};