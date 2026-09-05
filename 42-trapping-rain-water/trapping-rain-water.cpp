class Solution {
public:
    int trap(vector<int>& nums) {
        vector<int>leftmax(nums.size());
        vector<int>rightmax(nums.size());
        leftmax[0]=nums[0];
        rightmax[nums.size()-1]=nums[nums.size()-1];
        // computing left max:
        for(int i=1;i<nums.size();i++){
            leftmax[i]=max(leftmax[i-1],nums[i-1]);
        }
        //computing rightmax:
        for(int i=nums.size()-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],nums[i+1]);
        }
        //finding the water trapped
        int trapwater=0;
        for(int i=0;i<nums.size();i++){
            int currwater= min(leftmax[i],rightmax[i])-nums[i];
            if(currwater>0) trapwater+=currwater;
        }
        return trapwater;
    }
};