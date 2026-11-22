class Solution {
public:
    bool checkString(string s) {
        int a=-1;
        int b=-1;
        for(int i=0;i<s.size();i++){
           if(s[i]=='b') {
            b=i;
            break;
           }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a'){
                a=i;
                break;
            }
        }
        if(b==-1) return true;
        return a<b;
    }
};