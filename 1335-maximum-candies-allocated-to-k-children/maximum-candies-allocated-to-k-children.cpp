class Solution {
public:
    long long sum(vector<int>&candies){
        long long total=0;
        for(int x:candies){
            total+=x;
        }
        return total;
    }
    long long funct(vector<int>&candies,long long Candies){
        long long total_candies=0;
        for(int i=0;i<candies.size();i++){
            total_candies+= (candies[i]/Candies);
            //if(candies[i]/Candies!=candies[i-1]/Candies) break;
        }
        return total_candies;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        if(sum(candies)<k) return 0;
        sort(candies.begin(),candies.end());
        int low=1;
        int high=high = *max_element(candies.begin(), candies.end());;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long candies_max= funct(candies,mid);
            if(candies_max>=k) low=mid+1;
            else high=mid-1;
        }
        return high;

    }
};