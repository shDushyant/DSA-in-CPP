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
        vector<int>hash(256,-1);
        int len=0;
        int l=0,r=0;
        int maxi=0;
        while(r<s.size()){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l) l= hash[s[r]]+1;
            }
        
        len= r-l+1;
        maxi=max(maxi,len);
        hash[s[r]]=r;
        r++; 
        }
        return maxi;
    }      
};