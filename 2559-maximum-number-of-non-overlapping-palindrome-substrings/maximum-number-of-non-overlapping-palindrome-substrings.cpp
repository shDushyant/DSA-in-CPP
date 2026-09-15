class Solution {
public:
    int maxPalindromes(string s, int k) {
        /*if(k>s.size()) return 0;         // this calculates all the palindrome substrings but we need non overlapping 
        int cnt=0;
        for(int i=0;i<=s.size()-k;i++){
            for(int j=k-1+i;j<s.size();j++){
                 bool flag= true;
                int l=i,r=j;
                while(l<r){
                if(s[l]!=s[r]) {
                    flag=false; 
                    break;}
                l++;
                r--;
                }
                if(flag==true){
                   cnt++;
                   break;
                } 
            }
        }
        return cnt;*/
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Find all palindromes
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {

                if(s[i] == s[j] &&
                   (j-i <= 1 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes using s[0...i-1]
        vector<int> dp(n+1, 0);

        for(int i = 1; i <= n; i++) {

            // Don't use character i-1
            dp[i] = dp[i-1];

            // Try palindrome ending at i-1
            for(int j = 0; j < i; j++) {

                if(i-j >= k && pal[j][i-1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];

    }
};