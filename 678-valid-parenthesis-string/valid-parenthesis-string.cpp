class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                maxi+=1;
                mini+=1;
            }
            else if(s[i]==')'){
                maxi-=1;
                mini-=1;
            }
            else{
                maxi+=1;
                mini-=1;
            }
            if(mini<0) mini=0;
            if(maxi<0) return false;
        }
        return (mini==0);
    }
};