class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt=0;
        set<vector<int>>st;
        for(int i=0;i<digits.size();i++){
            if(digits[i]==0) continue;
            for(int j=0;j<digits.size();j++){
                if(i==j) continue;
                for(int k=0;k<digits.size();k++){
                     if(j==k || k==i) continue;
                     if(digits[k]%2==0) st.insert({digits[i],digits[j],digits[k]});

                }
            }
        }
        return st.size();
    }
};