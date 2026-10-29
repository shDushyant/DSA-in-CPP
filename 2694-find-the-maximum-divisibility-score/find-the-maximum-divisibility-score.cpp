class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans=INT_MAX;
        int score=0;
        for(int i=0;i<divisors.size();i++){
            int cnt =0;
            for(int j=0;j<nums.size();j++){
              if((nums[j]%divisors[i])==0) cnt++;
            }
            if(cnt>score) {
                ans=divisors[i];
                score=cnt;
            }
            else if( cnt==score) {
                ans=min(ans,divisors[i]);
                score=cnt;
            }
        }
        return ans;
    }
};