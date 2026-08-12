class Solution {
public:
    bool rotateString(string s, string goal) {
       /* if(s.size()!=goal.size()) return false;
        int idx=-1;
        for(int i=0;i<goal.size();i++){
            if(goal[i]==s[0]){
                idx=i;
                break;
            }
        }
        if(idx==-1) return false;
        //int k= s.size()%idx;
         for(int k = 0; k < idx; k++) {
            char temp = s[0];

            for(int j = 0; j < s.size() - 1; j++) {
                s[j] = s[j + 1];
            }

            s[s.size() - 1] = temp;
         }
        return s==goal; */
        if(s.size() != goal.size())
            return false;
        s= s+s;
        if(s.find(goal)<=s.size()) return true;
        return false;
    }
};