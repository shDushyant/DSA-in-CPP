
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60, 0);
        int cnt = 0;

        for(int x : time) {
            int rem = x % 60;
            int need = (60 - rem) % 60;

            cnt += freq[need];

            freq[rem]++;
        }

        return cnt;
    }
};
