class Solution {
public:
    /*vector<int>binary(int n){              brute force with memory limit exceeded
        vector<int>ans;
        while(n!=1){
            if(n&1) ans.push_back(1);
            else ans.push_back(0);
            n= n>>2;
            }
            return ans;
    }
    int minBitFlips(int start, int goal) {
       vector<int>s= binary(start);
       vector<int>g=binary(goal); 
       int cnt=0;
       for(int i=0;i<g.size();i++){
        if(g[i]!=s[i]) cnt++;
       }
       return cnt;*/
       int minBitFlips(int start, int goal){
        int cnt=0;
       while(start!=0 || goal!=0){
        if((start&1)!=(goal&1)){
            cnt++;
         } 
        start=start>>1;
        goal=goal>>1;
       }
       return cnt;

    }
};