class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        for (int i = 0; i < n; i++) {

            int t = target[i] - 'a';

            // Try to keep prefix equal to target
            if (freq[t] == 0) {

                // We cannot match target[i].
                // Find the smallest character greater than target[i].
                for (int c = t + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;

                        // Fill remaining characters smallest first
                        for (int x = 0; x < 26; x++) {
                            while (freq[x]--) {
                                ans += char('a' + x);
                            }
                        }

                        return ans;
                    }
                }

                // Need to backtrack.
                break;
            }

            ans += target[i];
            freq[t]--;
        }

        // Backtrack through the matched prefix.
        for (int i = (int)ans.size() - 1; i >= 0; i--) {

            freq[ans[i] - 'a']++;

            int t = target[i] - 'a';

            // Find smallest character > target[i]
            for (int c = t + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string res = ans.substr(0, i);
                    res += char('a' + c);
                    freq[c]--;

                    // Fill suffix in ascending order
                    for (int x = 0; x < 26; x++) {
                        while (freq[x] > 0) {
                            res += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return res;
                }
            }
        }

        return "";
    }
};