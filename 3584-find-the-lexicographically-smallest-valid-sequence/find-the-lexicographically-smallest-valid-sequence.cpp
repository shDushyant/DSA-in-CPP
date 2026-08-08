class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i] = maximum number of characters of word2
        // that can be matched from the END using word1[i...]
        vector<int> dp(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                dp[i] = dp[i + 1] + 1;
                j--;
            }
        }

        vector<int> ans;
        int i = 0;
        j = 0;

        // Find prefix, using at most one mismatch
        while (i < n && j < m) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else {
                // Use this position as the ONE mismatch.
                // The rest of word2 must be matched exactly.
                int remaining = m - j - 1;

                if (dp[i + 1] >= remaining) {
                    ans.push_back(i);
                    j++;
                    i++;

                    // Mismatch has been used.
                    break;
                }
            }

            i++;
        }

        // If we couldn't even choose all characters
        if (j == m)
            return ans;

        // Match the remaining characters exactly
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            i++;
        }

        if (j != m)
            return {};

        return ans;
    }
};