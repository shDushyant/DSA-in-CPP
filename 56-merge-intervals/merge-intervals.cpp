class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        // Put first interval
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {

            // Overlapping
            if (nums[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], nums[i][1]);
            }

            // Non-overlapping
            else {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};