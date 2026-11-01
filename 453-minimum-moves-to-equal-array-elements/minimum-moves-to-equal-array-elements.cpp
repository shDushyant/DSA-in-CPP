class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        if(nums[0]==nums[n-1]) return 0;
        int mn= nums[0];
        int cnt=0;
        for(int i=0;i<n;i++){
            int diff=nums[i]-mn;
            cnt+=diff;
        }
        return cnt;
    }
};