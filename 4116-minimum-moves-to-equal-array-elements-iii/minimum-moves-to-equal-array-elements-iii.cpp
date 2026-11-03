class Solution {
public:
    int minMoves(vector<int>& nums) {
        int target= *max_element(nums.begin(),nums.end());
        int min_moves=0;
        for(int x:nums){
            min_moves+=(target-x);
        }
    return min_moves;
    }
};