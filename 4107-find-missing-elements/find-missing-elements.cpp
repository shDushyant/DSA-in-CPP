class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>list={};
       // unordered_map<int,int>mpp;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int a=nums[0];
        int b=nums[nums.size()-1];
        while(i<=j && a<b){
          if(nums[i]==a) {
            i++;
            a++;
          }
          else {
            list.push_back(a);
            a++;
        }
        }
        
        return list;    
    }
};