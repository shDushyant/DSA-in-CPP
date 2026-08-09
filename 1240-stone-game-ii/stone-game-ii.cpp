class Solution {
public:
    int stoneGameII(vector<int>& piles) {
          int n = piles.size();
        
        // suffixSum[i] = sum of piles[i..n-1]
        vector<int> suffixSum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // dp[i][m] = max stones current player can secure from piles[i..] with param m
        // m is capped at n (beyond that, "take everything" always applies)
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        function<int(int, int)> solve = [&](int i, int m) -> int {
            if (i >= n) return 0;
            if (n - i <= 2 * m) return suffixSum[i];       // take all remaining piles
            if (dp[i][m] != -1) return dp[i][m];
            
            int best = 0;
            for (int X = 1; X <= 2 * m; X++) {
                if (i + X > n) break;
                int nextM = min(n, max(m, X));               // cap m at n
                int val = suffixSum[i] - solve(i + X, nextM);
                best = max(best, val);
            }
            
            dp[i][m] = best;
            return best;
        };
        
        return solve(0, 1);
    }
};