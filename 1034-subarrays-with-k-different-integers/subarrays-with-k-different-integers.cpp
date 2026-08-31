class Solution {
public:
    int goodArray(vector<int>&nums,int k){
       int l=0,r=0,cnt=0;
        unordered_map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       /* int cnt=0;                           // brute force sol with TC O(N*N)
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>mpp;
            for(int j=i;j<nums.size();j++){
               mpp[nums[j]]++;
               if(mpp.size()==k) cnt++;
               if(mpp.size()>k) break;
            }
        }
        return cnt;*/
        
        return goodArray(nums,k)-goodArray(nums,k-1);
    }
};