class Solution {
public:
    int ways(vector<int>& quantities, int types){
        int total_types=0;
        for(int i=0;i<quantities.size();i++){
            total_types+=ceil((double)quantities[i]/(double)types);
        }
        return total_types;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        if(quantities.size()==1){
           if(n<=quantities[0]) return quantities[0];
        } 
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int total_ways= ways(quantities,mid);
            if(total_ways<=n) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};