class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int pos=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            pos=i;
        }
       // if(pos==-1) return 0;
        int len=0;
        while(pos>=0 && s[pos]!=' '){
            len++;
            pos--;
        }
        return len;
    }
};