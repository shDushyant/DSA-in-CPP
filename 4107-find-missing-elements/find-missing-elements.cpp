class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        /*vector<int>list={};
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int a=nums[0];
        int b=nums[nums.size()-1];
        while(i<=j && a<b){
          if(nums[i]==a) {
            i++;
            a++;
          }
          else {
            list.push_back(a);
            a++;
        }
        }
        
        return list; */  // this is the better apprah as too many variables are there
        // this is the optimal approach
        vector<int> ans;
        if (nums.empty()) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            int curr = nums[i];

            while (curr + 1 < nums[i + 1]) {
                ans.push_back(curr + 1);
                curr++;
            }
        }

        return ans;   
    }
};