class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end()))
            return 0;

        if (n == 2)
            return -1;

        char first = s.front();
        char last = s.back();

        char smallest = *min_element(s.begin() + 1, s.end() - 1);
        char largest = *max_element(s.begin() + 1, s.end() - 1);

        if (first <= last && (first <= smallest || last >= largest))
            return 1;

        if (first > largest && last < smallest)
            return 3;

        return 2;
    }
};