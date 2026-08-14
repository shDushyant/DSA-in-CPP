class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0;
        int windsize=0; int maxi= INT_MIN;
        unordered_map<char,int>mpp;
        while(j<s.size()){
            mpp[s[j]]++;
            if(mpp[s[j]]<=2){
                windsize++;
                j++;
            }
            else{
                maxi= max(windsize,maxi);
                windsize=0;
                mpp.clear();
                i++;
                //swap(i,j);
                j=i;
            }
            maxi= max(maxi,windsize);

        }
        return maxi;
    }
};