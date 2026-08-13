class Solution {
public:
    int firstUniqChar(string s) {
        /*for(int i=0;i<s.size();i++){          this was brute force;
             int cnt=0;
            for(int j=0;j<s.size();j++){
            if(s[i]==s[j]) cnt++;
        }
        if(cnt==1) return i;
    }
        return -1;*/
      unordered_map<char,int>mpp;
      queue<int>q;
      for(int i=0;i<s.size();i++){
        if(mpp.find(s[i])==mpp.end()) q.push(i);
        mpp[s[i]]++;
        while(q.size()>0 && mpp[s[q.front()]]>1) q.pop();
      }
      if(q.empty()) return -1;
      return q.front();
    }  
};