class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<int> dp(piles);

        for (int len = 2; len <= n; len++) {
            for (int i = n - len; i >= 0; i--) {

                int j = i + len - 1;

                dp[j] = max(
                    piles[i] - dp[j],
                    piles[j] - dp[j - 1]
                );
            }
        }

        return dp[n - 1] >= 0;
        
    }
};