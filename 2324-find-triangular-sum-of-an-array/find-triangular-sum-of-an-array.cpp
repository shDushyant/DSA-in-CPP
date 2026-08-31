class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int i=0;
        int temp=1;
        while(i<nums.size()-1){
            nums[i]=(nums[i]+nums[temp])%10;
            i++;
            temp++;
        }
       if(!nums.empty()) {
          nums.pop_back();
          }
        return triangularSum(nums); 
    }
};