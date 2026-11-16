class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;

        string ds = "";
        int i = 0;

        while(i + k <= s.size()) {
            int sum = 0;

            for(int j = i; j < i+k; j++) {
                sum += (s[j]-'0');
            }

            ds += to_string(sum);
            i += k;
        }

        int sum = 0;

        while(i < s.size()) {
            sum += (s[i]-'0');
            i++;
        }

        if(i > 0 && s.size() % k != 0) {
            ds += to_string(sum);
        }

        return digitSum(ds, k);
    }
};