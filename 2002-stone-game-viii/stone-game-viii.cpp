class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
         int n = stones.size();

        // Convert stones into prefix sums
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Initially, the only possible move leaves us with
        // the total prefix sum.
        int ans = stones[n - 1];

        // Work backwards
        for (int i = n - 2; i >= 1; i--) {
            ans = max(ans, stones[i] - ans);
        }

        return ans;
    }
};