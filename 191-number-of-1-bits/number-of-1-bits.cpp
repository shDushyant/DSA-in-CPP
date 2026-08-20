class Solution {
public:
    int hammingWeight(int n) {
        vector<int>ans;
        while(n!=1){
            if(n%2==1) ans.push_back(1);
            else ans.push_back(0);
            n/=2;
        }
        int cnt=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1) cnt++;
        }
        return cnt+1;
    }
};