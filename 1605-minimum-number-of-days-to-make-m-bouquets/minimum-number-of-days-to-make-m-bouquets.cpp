class Solution {
public:
    
    int function(vector<int>&bloomDay,int days,int m,int k){
        int cnt=0;
        int no_of_bouque=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                cnt++;
            }
            else{
                no_of_bouque += cnt/k;
                cnt=0;
            }     
    }
             no_of_bouque += (cnt/k); 
             return no_of_bouque;
        }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
          return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int  bouque= function(bloomDay,mid,m,k);
            if(bouque>=m){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;  
    }
    
};