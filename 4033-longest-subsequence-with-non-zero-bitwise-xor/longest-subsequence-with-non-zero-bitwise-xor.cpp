class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        /*int leng_subsequence=1;
        int maxi_leng=0;
        int XOR=0;
        for(int i=0;i<nums.size();i++){
           XOR^=nums[i];
           if(XOR!=0) leng_subsequence++;
           else{
            leng_subsequence--;
           }
           maxi_leng= max(maxi_leng,leng_subsequence);
        }
        if(maxi_leng!=0) return maxi_leng-1;*/

         int x = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            x ^= num;
            if (num != 0)
                hasNonZero = true;
        }

        if (x != 0)
            return nums.size();

        if (hasNonZero)
            return nums.size() - 1;

        
      return 0;  
    }
};