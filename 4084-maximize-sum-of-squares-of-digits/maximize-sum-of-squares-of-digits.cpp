class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       /* long long smallest = pow(10, num - 1);
        long long largest = pow(10, num) - 1;

        for (long long i = largest; i >= smallest; i--) {
            int sum1 = 0;
            long long temp = i;

            while (temp > 0) {
                sum1 += (temp % 10) * (temp % 10);
                temp /= 10;
            }

            if (sum1 == sum) {
                return to_string(i);
            }
        }

        return "";*/
        if (sum > 9 * num) return "";

        string res(num, '0');
        int i = 0;
        while (sum >= 9) {
            res[i++] = '9';
            sum -= 9;
        }
        if (sum > 0) res[i] = '0' + sum;
        return res;
    }
};