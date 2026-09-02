class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        if(nums[0]>5) return false;
        int fives=0,tens=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==5) fives+=1;
            else if(nums[i]==10){
                if(fives){
                    tens+=1;
                    fives-=1;
                }
                else return false;
            }
            else{
                if(tens>0&&fives>0){
                    fives-=1;
                    tens-=1;
                }
                else if(fives>=3) fives-=3;
                else return false;
            }
        }
        return true;
    }
};