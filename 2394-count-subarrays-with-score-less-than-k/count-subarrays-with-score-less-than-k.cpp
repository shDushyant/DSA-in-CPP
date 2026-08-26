class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        /*int cntmax=0;      //brute force;
        for(int i=0;i<nums.size();i++){
            long long sum=0; int cnt=0;
            for(int j=i;j<nums.size();j++){
              sum+=nums[j];
              cnt++;
              if(sum*cnt<k) cntmax++;
              else break;
            }
        }
        return cntmax;*/ 
        int l = 0;
        long long sum = 0;
        long long cnt = 0;

        for (int r = 0; r < nums.size(); r++) {

            sum += nums[r];

            while (l <= r && sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }

            // All subarrays ending at r and starting from l...r
            // satisfy the condition.
            cnt += (r - l + 1);
        }

        return cnt;


    }
};