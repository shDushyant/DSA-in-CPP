/*class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int mid= (n/2)+1;             //extreme brute force;
        int cnt=0;
        for(int i=mid;i>=1;i--){
            int sum=i;
            for(int j=i-1;j>=1;j--){
                sum+=j;
                if(sum==n){
                 cnt++;
                 break;
                }
            }
        }
        return cnt+1;

    }
};*/
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt = 0;

        for (long long k = 1; k * (k + 1) / 2 <= n; k++) {

            long long rem = n - k * (k - 1) / 2;

            if (rem % k == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};