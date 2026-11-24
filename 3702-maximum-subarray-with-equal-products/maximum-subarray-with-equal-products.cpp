class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxi=1;
        for(int i=0;i<nums.size();i++){
            long long  gcd1=nums[i];
            long long  lcm1=nums[i];
            long long  prod= nums[i];
            for(int j=i+1;j<nums.size();j++){
                prod*=nums[j];
                 if (prod > 25200) break;
                gcd1=gcd(gcd1,nums[j]);
                lcm1=lcm(lcm1,nums[j]);
                if(prod==(gcd1*lcm1)){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};