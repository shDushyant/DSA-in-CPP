class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int l=0,r=0, maxi=0;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()<=2){
                maxi=max(maxi,r-l+1);
            }
            if(mpp.size()>2){
                while(mpp.size()>2){
                     mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                    l++;
                }
            }
            r++;
        }
       return maxi;
        
    }
};