class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;

        long long even = 1, odd = 0;
        long long sum = 0, cnt = 0;

        for(int x : arr) {
            sum += x;

            if(sum % 2 == 0) {
                cnt += odd;
                even++;
            }
            else {
                cnt += even;
                odd++;
            }

            cnt %= mod;
        }

        return cnt;
    }
};