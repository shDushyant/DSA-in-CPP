class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=0;
        int f=0,s1=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                bool flag=true;
                int l=i,r=j;
                while(l<=r){
                    if(s[l]!=s[r]) {
                        flag=false;
                        break;
                }
                l++;
                r--;
                }
                if(flag==true){
                    if((j-i+1)>maxi){
                        maxi=j-i+1;
                        f=i,s1=j;
                    }
                }
            }
        }
        string ans="";
        for(int i=f;i<=s1;i++){
            ans+=s[i];
        }
       return ans;
    }
};