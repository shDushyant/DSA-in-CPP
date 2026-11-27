/*class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        //if(space>=*max_element(nums.begin(),nums.end())) return *min_element(nums.begin(),nums.end());
        int maxtar=0;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int target=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]-nums[i])%space==0) target++;
            }
            if(target==maxtar){
             mini=min(mini,nums[i]);
            }
            if(target>maxtar){
                maxtar=target;
                mini=nums[i];
            }
        }
        return mini;
    }
};*/ //this was the brute force 
  
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> mp;

        // Count frequency of each remainder
        for(int x : nums) {
            mp[x % space]++;
        }

        int maxi = 0;
        int ans = INT_MAX;

        // Find the smallest number from the
        // group having maximum frequency
        for(int x : nums) {
            int rem = x % space;

            if(mp[rem] > maxi) {
                maxi = mp[rem];
                ans = x;
            }
            else if(mp[rem] == maxi) {
                ans = min(ans, x);
            }
        }

        return ans;
    }
};
