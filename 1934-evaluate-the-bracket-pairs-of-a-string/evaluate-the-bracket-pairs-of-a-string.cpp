class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]]= knowledge[i][1];
        }
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                string ans="";
                i++;
                while(s[i]!=')'){
                    ans+=s[i];
                    i++;
                }
                if(mpp.find(ans)!=mpp.end()){
                    res+=mpp[ans];
                }
                else res+='?';
                continue;
            }
            res+=s[i];
        }
        
        return res;
    }
};