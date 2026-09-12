/*class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
    }
};*/
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, original_index}
        vector<vector<int>> a;

        for(int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1],
                         intervals[i][2], i});
        }

        // Sort according to ending point
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            if(x[1] != y[1])
                return x[1] < y[1];
            return x[3] < y[3];
        });

        // Store all ending points
        vector<int> ends(n);

        for(int i = 0; i < n; i++) {
            ends[i] = a[i][1];
        }

        // dp[i][k] = best answer using first i intervals
        // with at most k intervals
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));

        vector<vector<vector<int>>> ans(
            n + 1, vector<vector<int>>(5)
        );

        for(int i = 1; i <= n; i++) {

            int l = a[i-1][0];
            int weight = a[i-1][2];
            int index = a[i-1][3];

            // Number of previous intervals having
            // ending point < current starting point
            int p = lower_bound(ends.begin(), ends.end(), l) - ends.begin();

            for(int k = 1; k <= 4; k++) {

                // Don't take current interval
                dp[i][k] = dp[i-1][k];
                ans[i][k] = ans[i-1][k];

                // Take current interval
                long long takeScore = dp[p][k-1] + weight;

                vector<int> takeAns = ans[p][k-1];
                takeAns.push_back(index);

                // Indices must be sorted for lexicographical comparison
                sort(takeAns.begin(), takeAns.end());

                if(takeScore > dp[i][k]) {

                    dp[i][k] = takeScore;
                    ans[i][k] = takeAns;

                }
                else if(takeScore == dp[i][k] &&
                        takeAns < ans[i][k]) {

                    ans[i][k] = takeAns;
                }
            }
        }

        return ans[n][4];
    }
};