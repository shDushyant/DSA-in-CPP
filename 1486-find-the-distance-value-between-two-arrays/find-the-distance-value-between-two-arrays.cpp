class Solution {
public:
    /*int check_num(vector<int>&arr2,int target){
        int low=0,high=arr2.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr2[mid]==target) return 1;
            else if(arr2[mid]<target) low=mid+1;
            else high =mid-1;
        }
        return 0;
    }*/
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       /* int cnt=0;         brute force
        int maxi=0;
        for(int i=0;i<arr1.size();i++){
            cnt++;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d) cnt=0;  
            }
            if(cnt==1) maxi+=cnt;
            maxi= max(maxi,cnt);
        }
        return maxi;*/
        int maxi=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            int cnt=1;
          int low=0;int high=arr2.size()-1;
          while(low<=high){
            int mid=low+(high-low)/2;
            if(arr2[mid] < arr1[i] - d) {
               low = mid + 1;
            }
            else if(arr2[mid] > arr1[i] + d) {
              high = mid - 1;
             }
              else {
             cnt = 0;
             break;
            }
          }
          maxi=maxi+cnt;
        }
        return maxi;
    }
};