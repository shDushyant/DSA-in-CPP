class Solution {
public:
    int missingInteger(vector<int>& nums) {
        //if(nums.size()==1) return nums[0]+1;
        long sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==(nums[i-1]+1)){
                sum+=nums[i];
            }
            else break;
        }
        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest missing number >= sum
        while (st.count(sum)) {
            sum++;
        }

        return sum;
        
        

    }
};