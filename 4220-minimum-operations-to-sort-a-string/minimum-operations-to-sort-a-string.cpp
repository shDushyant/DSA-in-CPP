class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;               // unsorted, only length-1 substrings are allowed

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // 1 op: first char is already the min, or last char is already the max
        if (s[0] == mn || s[n - 1] == mx) return 1;

        // 2 ops: 
        // A) sort [0..n-2] (brings a min to the front), then sort [1..n-1]
        //    works if the min appears somewhere in [0..n-2]
        // B) sort [1..n-1] (brings a max to the back), then sort [0..n-2]
        //    works if the max appears somewhere in [1..n-1]
        bool minInPrefix = false, maxInSuffix = false;
        for (int i = 0; i < n - 1; i++) if (s[i] == mn) { minInPrefix = true; break; }
        for (int i = 1; i < n; i++)     if (s[i] == mx) { maxInSuffix = true; break; }
        if (minInPrefix || maxInSuffix) return 2;

        // Otherwise the max is only at index 0 and the min is only at index n-1
        return 3;
    }
};