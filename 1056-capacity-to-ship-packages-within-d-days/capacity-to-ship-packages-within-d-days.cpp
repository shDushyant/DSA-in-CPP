class Solution {
public:
    int sum(vector<int>&weights){
        int sum=0;
        for(int x:weights){
            sum+= x;
        }
        return sum;
    }
    int function(vector<int>&weights,int capacity){
        int day=1, load=0;
        for(int i=0;i<weights.size();i++){
            if(load+ weights[i]>capacity){
                day+=1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
            return day;
        }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high= sum(weights);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int req_days= function(weights,mid);
            if(req_days<=days){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};