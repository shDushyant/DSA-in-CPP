class Solution {
public:
    long long function(vector<int>& piles, int hourly){
        long total_time=0;
        for(int i=0;i<piles.size();i++){
            total_time+= ceil((double)piles[i]/(double)hourly);
        }
        return total_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long total_hrs= function(piles,mid);
            if(total_hrs<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
        
    }
};