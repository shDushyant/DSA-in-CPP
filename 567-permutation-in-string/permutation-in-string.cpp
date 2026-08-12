class Solution {
public:
    bool isfreqsame( vector<int>&freq, vector<int>&windfreq){
        for(int i=0;i<26;i++){
            if(freq[i]!=windfreq[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0);
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        int windsize= s1.size();
        for(int i=0;i<s2.size();i++){
            vector<int>windfreq(26,0);
            int idx=i;
            int windidx=0;
            while(windidx<windsize && idx<s2.size()){
                windfreq[s2[idx]-'a']++;
                windidx++;
                idx++;
            }
            if(isfreqsame(freq,windfreq)) return true;
        }
        return false;
        
    }
};