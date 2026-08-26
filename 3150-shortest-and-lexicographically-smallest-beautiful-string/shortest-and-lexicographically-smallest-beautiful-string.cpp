class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0;
        int ones = 0;
        string ans = "";

        for (int r = 0; r < s.size(); r++) {

            if (s[r] == '1')
                ones++;

            while (ones > k) {
                if (s[l] == '1')
                    ones--;
                l++;
            }

            if (ones == k) {

                while (s[l] == '0')
                    l++;

                string candidate = s.substr(l, r - l + 1);

                if (ans.empty() ||
                    candidate.length() < ans.length() ||
                    (candidate.length() == ans.length() &&
                     candidate < ans)) {
                    ans = candidate;
                }
            }
        }

        return ans;
    }
};