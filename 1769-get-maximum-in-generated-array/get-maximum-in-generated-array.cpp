class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        if(n>0 && n<=2) return 1;
        vector<int>nums(n+1,0);
        nums[0]=0;
        nums[1]=1;
        for(int i=2;i<=n;i++){
          if(i%2==0){
            int k=i/2;
            nums[i]=nums[k];
          }
          else{
            int k= (i-1)/2;
            nums[i]=nums[k]+nums[k+1];
          }
        }
        return *max_element(nums.begin(),nums.end());
    }
};