class Solution {
public:
    int SUM(int n){
        int temp=n;
        int sum=0;
        while(temp>0){
            sum+= (temp%10);
            temp=temp/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int sum= SUM(nums[i]);
            if(sum==i) return i;
        }
        return -1;
    }
};