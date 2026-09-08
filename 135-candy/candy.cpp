class Solution {
public:
    int candy(vector<int>& nums) {
        if(nums.size()==1) return 1;
        vector<int>canda(nums.size());
        int candies=0;
        canda[0]=1;
        canda[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) canda[i]=canda[i-1]+1;
            else canda[i]=1;
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1]) canda[i]=max(canda[i],canda[i+1]+1);
        }
        for(int x:canda){
            candies+=x;
        }
        return candies;
    }
};