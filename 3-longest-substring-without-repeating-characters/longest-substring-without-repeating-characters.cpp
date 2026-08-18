class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*int n=s.length();   // brute force sliding window with o(n^2)
        int maxcnt=0;
        int cnt=0;
        int i=0,j=0;
        unordered_map<char,int>mpp;
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                maxcnt=max(maxcnt,cnt);
                cnt=0;
                mpp.clear();
                i++;
                j=i;
             }
           else{ mpp[s[j]]++;
            cnt++;
            j++;
           }
        }
        maxcnt= max(cnt,maxcnt);
        return maxcnt;   */

        int i = 0, j = 0;
        int maxcnt = 0;

        unordered_map<char, int> mpp;

        while (j < s.length()) {

            mpp[s[j]]++;

            while (mpp[s[j]] > 1) {
                mpp[s[i]]--;
                i++;
            }

            maxcnt = max(maxcnt, j - i + 1);
            j++;
        }

        return maxcnt;
    }      
};