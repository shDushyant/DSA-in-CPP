class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
            if(nums1[0]%2!=0){
                for(int i=1;i<nums1.size()-1;i++){
                if(nums1[i]%2==0){
                    if(nums1[i]-nums1[0]<1 || (nums1[i]-nums1[0])%2==0) return false;
                }
            }
            }
            else{ 
                for(int i=1;i<nums1.size();i++){
                    if(nums1[i]%2!=0){
                        if((nums1[i]-nums1[0])%2!=0) return false;
                    }
                }

            }
        
        return true;

    }
};