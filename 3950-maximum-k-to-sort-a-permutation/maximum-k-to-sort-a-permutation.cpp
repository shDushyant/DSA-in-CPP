class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())) return 0;
        int k=-1; 
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                k= k&nums[i];
            }
        } 
      return k==-1?0:k;
    }
};