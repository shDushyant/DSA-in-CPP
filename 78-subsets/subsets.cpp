class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>>list;
      int n= 1<<nums.size();
      for(int i=0;i<n;i++){
        vector<int>ans;
        for(int j=0;j<nums.size();j++){
         if(i&(1<<j)) ans.push_back(nums[j]);
        }
        list.push_back(ans);
      }
      return list;
    }
};