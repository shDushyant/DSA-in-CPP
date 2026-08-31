class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};

        int l = 0, r = 0;
        int minlen = INT_MAX;
        int cnt = 0;
        int stidx = -1;

        for(char c : t)
            hash[c]++;

        while(r < s.size()) {

            if(hash[s[r]] > 0) {
                cnt++;
            }

            hash[s[r]]--;

            while(cnt == t.size()) {

                if(r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    stidx = l;
                }

                hash[s[l]]++;

                if(hash[s[l]] > 0)
                    cnt--;

                l++;
            }

            r++;
        }

        return stidx == -1 ? "" : s.substr(stidx, minlen);
    }
};