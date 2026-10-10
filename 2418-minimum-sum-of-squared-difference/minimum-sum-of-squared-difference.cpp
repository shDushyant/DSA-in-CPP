
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> diff(nums1.size());

        long long sum = 0;
        long long mx = 0;

        for(int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if(sum <= k) return 0;

        long long low = 0, high = mx;

        // Find the smallest maximum difference achievable
        while(low < high) {
            long long mid = low + (high - low) / 2;
            long long need = 0;

            for(long long d : diff) {
                if(d > mid) need += d - mid;
            }

            if(need <= k) high = mid;
            else low = mid + 1;
        }

        long long limit = low;
        long long remaining = k;

        // Reduce all differences greater than limit to limit
        for(long long d : diff) {
            if(d > limit) {
                remaining -= d - limit;
                d = limit;
            }
        }

        // Rebuild differences at the limit and compute the answer
        long long ans = 0;
        for(long long d : diff) {
            if(d > limit) d = limit;
            ans += d * d;
        }

        // Use any leftover operations to reduce differences at limit
        // One reduction from limit to limit-1 saves 2*limit-1.
        // The leftover operations are fewer than the number of
        // differences equal to limit after the leveling step.
        long long count = 0;
        for(long long d : diff) {
            if(d >= limit && limit > 0) count++;
        }

        long long use = min(remaining, count);
        ans -= use * (2 * limit - 1);

        return ans;
    }
};

