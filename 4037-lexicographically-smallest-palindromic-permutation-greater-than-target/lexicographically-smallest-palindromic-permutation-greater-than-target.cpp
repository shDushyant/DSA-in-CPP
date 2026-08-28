class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int half = n / 2;

        // Frequency of characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Find middle character
        char mid = 0;
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
                cnt[i]--;
            }
        }

        // More than one odd frequency => palindrome impossible
        if (odd > 1)
            return "";

        // Remove the characters required by target's first half.
        // We are trying to make the first half equal to target first.
        for (int i = 0; i < half; i++) {
            cnt[target[i] - 'a'] -= 2;
        }

        auto valid = [&]() {
            for (int x : cnt) {
                if (x < 0)
                    return false;
            }
            return true;
        };

        // ----------------------------------------------------
        // Case 1:
        // The first half can exactly match target's first half.
        // ----------------------------------------------------
        if (valid()) {

            string left = target.substr(0, half);

            string right = left;
            reverse(right.begin(), right.end());

            if (n % 2)
                right = string(1, mid) + right;

            // Since left halves are equal, compare the remaining
            // right side with target's right side.
            if (right > target.substr(half)) {
                return left + right;
            }
        }

        // ----------------------------------------------------
        // Case 2:
        // Backtrack from the rightmost position of the first half.
        // Make that position slightly larger than target[i].
        // ----------------------------------------------------
        for (int i = half - 1; i >= 0; i--) {

            int current = target[i] - 'a';

            // Restore the pair that was used at target[i]
            cnt[current] += 2;

            if (!valid())
                continue;

            // Find the smallest character > target[i]
            for (int c = current + 1; c < 26; c++) {

                if (cnt[c] >= 2) {

                    // Use this character as the first half position
                    cnt[c] -= 2;

                    string left = target.substr(0, i);

                    left += char('a' + c);

                    // Fill remaining first-half positions
                    // with the smallest possible characters.
                    for (int x = 0; x < 26; x++) {
                        while (cnt[x] >= 2) {
                            left += char('a' + x);
                            cnt[x] -= 2;
                        }
                    }

                    // Build palindrome
                    string right = left;
                    reverse(right.begin(), right.end());

                    if (n % 2)
                        return left + string(1, mid) + right;
                    else
                        return left + right;
                }
            }
        }

        return "";
    }
};