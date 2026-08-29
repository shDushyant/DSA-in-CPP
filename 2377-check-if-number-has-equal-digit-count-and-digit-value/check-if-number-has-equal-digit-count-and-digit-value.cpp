class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int>mpp;
        for(int i=0;i<num.size();i++){
            mpp[num[i]-'0']++;
        }
        for(int i=0;i<num.size();i++){
            if(mpp[i]!=(num[i]-'0')) return false;
        }
        return true;
    }
};