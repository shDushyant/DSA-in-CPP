class Solution {
public:
    void funct(string &s,int n){
        if(n==1) return ;
         string ans = "";
        int i = 0;
        while(i < s.size()) {
            int cnt = 0;
            char ch = s[i];
            while(i < s.size() && s[i] == ch) {
                cnt++;
                i++;
            }
            ans += to_string(cnt);
            ans += ch;
        }
        s=ans;
       funct(s,n-1);
    }
    string countAndSay(int n) {
        string s="1";
        funct(s,n);
        return s; 
    }
};