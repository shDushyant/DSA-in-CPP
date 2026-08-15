class Solution {
public:
    int findval(vector<int>&nums1, int target){
        int low=0,high=nums1.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums1[mid]==target) return nums1[mid];
            else if(nums1[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        sort(nums1.begin(),nums1.end());
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums2.size();i++){
            if(mpp.find(nums2[i])!=mpp.end()) continue;
            mpp[nums2[i]]++;
            int target= findval(nums1,nums2[i]);
            if(target==nums2[i]) ans.push_back(nums2[i]);
            else continue;
        }
        return ans;
    }
};