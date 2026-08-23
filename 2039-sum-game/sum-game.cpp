class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q1++;
            else
                sum1 += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                sum2 += num[i] - '0';
        }

        int diff = sum1 - sum2;
        int qdiff = q1 - q2;

        // If number of ? is odd, Alice wins automatically
        // because the last move determines an imbalance.
        if (qdiff % 2 != 0)
            return true;

        // Each pair of '?' can create a difference of up to 9.
        return diff != -9 * qdiff / 2;
    }
};