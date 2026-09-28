class Solution {
public:
    int maxDepth(string s) {
        //stack<char>st;
        int cnt=0;
        int maxi_cnt=0;
        for(char c:s){
            if(c=='(') cnt++;
            else if(c==')') cnt--;
            maxi_cnt= max(maxi_cnt,cnt);
        }
        return maxi_cnt;
    }
};