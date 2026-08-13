class Solution {
public:
    int compress(vector<char>& chars) {
       /* unordered_map<char,int>mpp;
        for(char c: chars){
            mpp[c]++;
        }
        chars.clear();
        for(auto p:mpp){
            if(p.second==1) chars.push_back(p.first);
            else{
            chars.push_back(p.first);
            chars.push_back(p.second);
        }
        }
        return chars.size();*/
        int idx=0;
        for(int i=0;i<chars.size();){
            char ch= chars[i];
            int cnt=0;
            while(i<chars.size() && chars[i]==ch){
                cnt++;
                i++;
            }
            if(cnt==1) chars[idx++]=ch;
            else{
                chars[idx++]=ch;
                string str= to_string(cnt);
                for(char digit:str){
                    chars[idx++]=digit;
                }
            }
        }
        return idx;
    }
};