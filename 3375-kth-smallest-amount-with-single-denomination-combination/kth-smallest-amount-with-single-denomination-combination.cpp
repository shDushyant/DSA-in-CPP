/*class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
       vector<int>store;           //brute force 
       set<int>st;
       for(int i=0;i<coins.size();i++){
        for(int j=1;j<=k;j++){
            st.insert(coins[i]*j);
        }
       }
       for(auto it:st){
        store.push_back(it);
       }
       sort(store.begin(),store.end());
       return store[k-1]; 
       
    }
};*/


class Solution {
public:

    long long gcd(long long a, long long b) {
        while(b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        for(int mask = 1; mask < (1 << n); mask++) {

            long long LCM = 1;
            int bits = 0;
            bool valid = true;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {

                    bits++;

                    LCM = lcm(LCM, coins[i]);

                    if(LCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if(!valid)
                continue;

            long long curr = x / LCM;

            if(bits % 2 == 1)
                ans += curr;
            else
                ans -= curr;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while(low < high) {

            long long mid = low + (high - low) / 2;

            if(count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};